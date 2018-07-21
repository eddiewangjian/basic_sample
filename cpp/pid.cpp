#include <thread>
#include <iostream>
#include <stdlib.h>
#include <dirent.h>
#include <map>
#include <string>
#include <fstream>

#include <unistd.h>
#include <boost/algorithm/string.hpp>

void get_pids(std::map<std::string, std::string>& pids)
{
    pids.clear();

    DIR* dp = opendir("/proc");
    if (dp == nullptr) {
        std::cout << "Fail open dir:/proc" << std::endl;
        return;
    }   

    struct dirent* dirp;
    while ((dirp = readdir(dp)) != nullptr) {
        int id = atoi(dirp->d_name);
        if (id <= 0) {
            continue;
        }   

        std::string cmd_path = std::string("/proc/") + dirp->d_name + "/cmdline";
        std::ifstream file(cmd_path.c_str());

        std::string cmd;
        std::getline(file, cmd);
        if (cmd.empty()) {
            continue;
        }   

        auto it = pids.find(cmd);
        if (it != pids.end()) {
            pids[cmd] += ":" + std::to_string(id);
        } else {
            pids[cmd] = std::to_string(id);
        }   
    }   

    closedir(dp);
}

void trace_pid_tree(std::map<std::string, std::string>& map_pid_ppid) {
    map_pid_ppid.clear();

    DIR* dp = opendir("/proc");
    if (dp == nullptr) {
        std::cout << "Fail open dir:/proc" << std::endl;
        return;
    }   

    struct dirent* dirp;
    while ((dirp = readdir(dp)) != nullptr) {
        int id = atoi(dirp->d_name);
        if (id <= 0) {
            continue;
        }   

        std::string proc_file = std::string("/proc/") + dirp->d_name + "/stat";
        std::ifstream file(proc_file.c_str());

        std::string info;
        std::getline(file, info);
        if (info.empty()) {
            continue;
        }   
        
        std::vector<std::string> seg;
        boost::split(seg, info, boost::is_any_of(" "));
        map_pid_ppid[dirp->d_name] = seg[3];
    }

    return;
}


int main(int argc, char** argv) {
    pid_t pid = getpid();
    std::cout << pid << std::endl;
    std::map<std::string, std::string> pids;
    /*
    get_pids(pids);
    for (auto it = pids.begin(); it != pids.end(); it++) {
        std::cout << it->first << "=" << it->second << std::endl;
    }
    */
    
    std::map<std::string, std::string> map_pid_ppid;
    trace_pid_tree(map_pid_ppid);
    for (auto it = map_pid_ppid.begin(); it != map_pid_ppid.end(); it++) {
        std::cout << it->first << "=" << it->second << std::endl;
    }

    while (true) {
        sleep(10);
    }
}





