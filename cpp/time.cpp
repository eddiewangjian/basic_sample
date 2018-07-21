#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <unistd.h>
#include <sys/time.h>

#include <time.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

// get current precise time as us
struct timeval test1() {
    struct timeval time;
    int ret = gettimeofday(&time, NULL);
    printf("machine time: %ld s, %ld us\n", time.tv_sec, time.tv_usec);
    return time;
}

// show local time as date
void test2(struct timeval time) {
    struct tm* pTime;
    pTime = localtime(&time.tv_sec);
    printf("%4d-%02d-%02d %02d:%02d:%02d %03dms %03dus\n", pTime->tm_year+1900, pTime->tm_mon+1, pTime->tm_mday, pTime->tm_hour, pTime->tm_min, pTime->tm_sec, time.tv_usec/1000, time.tv_usec%1000);
    return;
}


int main(int argc, char** argv) {
    struct timeval ret = test1();
    test2(ret); 
}







