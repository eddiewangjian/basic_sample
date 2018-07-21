/***************************************************************************
 * 
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file main.cpp
 * @author map(com@baidu.com)
 * @date 2018/01/09 16:20:02
 * @brief 
 *  
 **/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <sys/resource.h>
#include <sys/statfs.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

double get_mem_status()
{
    std::ifstream fin("/proc/meminfo");
    std::unordered_map<std::string, long> mem_status;
    std::string line;
    boost::regex exptrim("\\s+");
    while (std::getline(fin, line)) {
        try {
            std::string line_nospace = boost::regex_replace(line, exptrim, " ");
            std::vector<std::string> res;
            boost::split(res, line_nospace, boost::is_any_of(" :\r\n"));
            mem_status[res[0]] = boost::lexical_cast<long>(res[2]);
        } catch (std::exception& e) {
        }
    }

    double cached = mem_status["Cached"] / 1024.;
    double buffer = mem_status["Buffers"] / 1024.;
    double free = mem_status["MemFree"] / 1024.;
    return (cached + free + buffer) / 1024.;
}

double get_disk_status()
{
    struct statfs disk_info;
    if (::statfs("/home/", &disk_info) == -1) {
        LOG(ERROR) << "Fail to get disk information";
        return 0;
    }

    return double(disk_info.f_bavail) / 1024. / 1024. /1024. * disk_info.f_bsize;
}

double get_cpu_status(int interval_seconds)
{
    long long user = 0;
    long long nice = 0;
    long long sys = 0;
    long long idle = 0;
    long long iowait = 0;
    long long irq = 0;
    long long softirq = 0;

    get_cpu_info(user, nice, sys, idle, iowait, irq, softirq);
    long long alls = user + nice + sys + idle + iowait + irq + softirq;
    long long idles = idle;

    std::this_thread::sleep_for(std::chrono::seconds(interval_seconds));

    get_cpu_info(user, nice, sys, idle, iowait, irq, softirq);
    long long alle = user + nice + sys + idle + iowait + irq + softirq;
    long long idlee = idle;

    return double(idlee - idles) / (alle - alls) * 100.;
}


int main(int argc, char* argv[]) {
    float disk = get_disk_status();
    printf("DISK: %f G", disk);

    float cpu_rate = get_cpu_status(1);
    printf("CPU: %f %", cpu_rate);

    double mem = get_mem_status();
    printf("MEM: %f G", cpu_rate);
    
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
