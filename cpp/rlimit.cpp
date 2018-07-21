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
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void test_mem(float rlim_m, float apply_m) {
    // mem 
    int ret;
    struct rlimit rl;
    
    ret = getrlimit(RLIMIT_RSS, &rl);
    cout << ret << " rss_cur:" << rl.rlim_cur << " rss_max:" << rl.rlim_max << endl;

    rl.rlim_cur = rl.rlim_max = rlim_m * 1024 * 1024;
    ret = setrlimit(RLIMIT_RSS, &rl);
    cout << ret << " rss_cur:" << rl.rlim_cur << " rss_max:" << rl.rlim_max << endl;

    int i;
    for (i = 0; i < apply_m * 1024; i++){
        int *p =(int *)malloc(1024);
        if(p == NULL){     
            printf("fail");
        }else{
            p[0] = i;
        }
    }
    printf("%d bytes allocted\n", i * 1024);
    return;
}


int main(int argc, char** argv) {
    test_mem(2, 1.);
    
    // cpu
    int temp = 0;
    while(1) {
        temp++;
    }
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
