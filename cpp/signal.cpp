#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <signal.h>
#include <unistd.h>

using namespace std;

void handler(int signal) {
    cout << "capture signal:" << signal << endl;
    return;
}

void test1() {
    signal(SIGTERM, handler);
    signal(SIGINT, handler);
    while (1) {
        sleep(5);
        cout << "hi" << endl;
    }
}

int main(int argc, char** argv) {
    test1(); 
}







