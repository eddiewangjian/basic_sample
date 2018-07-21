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
#include "stdio.h"
#include <thread>
#include <string>


using namespace std;

void sub_thread_func(void) {
    int i = 3;
    while(i) {
        printf("son-%d\n", i);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //system("touch son_running");
        i--;
    }
    return;
}

void sub_thread_func2(int a, int b) {
    int c = a + b;
    printf("son result=%d\n", c);
    return;
}


//close son when father end
void test1() {
    std::thread(&sub_thread_func).detach();
    cout << "main thread" << endl;
    return;
}

//father wait until son end
void test2() {
    std::thread td(sub_thread_func);
    td.join();
    cout << "main thread" << endl; 
    return;
}

//father run longer than son
void test3() {
    std::thread(&sub_thread_func).detach();
    
    int i = 5;
    while(i) {
        printf("father-%d\n", i);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i--;
    }
    return;
}

//son with multi parameter
void test4() {
    int a = 6;
    int b = 6;
    std::thread td(&sub_thread_func2, a, b);
    //td.detach();
    td.join();
    
    cout << "main thread" << endl; 
    return;
}

int main(int argc, char* argv[]) {
    test1();
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
