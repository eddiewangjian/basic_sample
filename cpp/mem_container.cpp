
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <typeinfo>
#include <string>

using namespace std;


void run_limit_mem(float rlim_m) {
    int ret;
    struct rlimit rl;
    
    ret = getrlimit(RLIMIT_RSS, &rl);
    //cout << ret << " rss_cur:" << rl.rlim_cur << " rss_max:" << rl.rlim_max << endl;

    rl.rlim_cur = rlim_m * 1024 * 1024 * 1024;
    ret = setrlimit(RLIMIT_RSS, &rl);
    //cout << ret << " rss_cur:" << rl.rlim_cur << " rss_max:" << rl.rlim_max << endl;

    return;
}


int main(int argc, char** argv) {
    if(argc < 3){
        printf("usage: ./mem_container limit_mem_g command_str\n");
        exit(-1);
    }

    float rlim_m = atof(argv[1]);
    printf("limit mem as %fG\n", rlim_m);
    run_limit_mem(rlim_m);
    
    string cmd;
    for(int i = 2; i < argc; i++) {
        cmd += argv[i];
        cmd += " ";
    }
    cout << cmd << endl;

    int ret = system(cmd.c_str());
    exit(ret);
}









