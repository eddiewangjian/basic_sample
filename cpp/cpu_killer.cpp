#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  

#include <sys/time.h>
#include <ctime>
#include <time.h>
#include <unistd.h>

using namespace std;
  
int main(int argc, char** argv)  
{  
	if (argc != 2) {
        cout << "usage: run_cpu LEVEL(1-6)" << endl;
        return 0;
    }
	
    int percent_level_map[] = {0, 0, 80, 200, 400, 650, 1000};
    
    int index = atoi(argv[1]);
    int facter = 0;
    if (index <= 0 || index > sizeof(percent_level_map)/sizeof(int) ) {
        cout << "usage: run_cpu LEVEL(1-6)" << endl;
        return 0;
    }
    facter = percent_level_map[index];
    
    //struct timeval time;
    //int ret = gettimeofday(&time, NULL);
    //cout << "a" << time.tv_sec << "." << time.tv_usec << endl;
    //float i = 0;
    //for (int j = 0; j < 10000; j++) {
    //    i = (i + 10) / 10;
    //}
    //ret = gettimeofday(&time, NULL);
    //cout << "b" << time.tv_sec << "." << time.tv_usec << endl;
    //usleep(20);
    //ret = gettimeofday(&time, NULL);
    //cout << "c" << time.tv_sec << "." << time.tv_usec << endl;
    
    srand((unsigned)time(NULL));
    while (true) {
		usleep(20);
        float i = 0;
        for (int j = 0; j < 10 * facter; j++) {
            i = (i + 10) / 10;
        }
	}
    return 0;  
} 
