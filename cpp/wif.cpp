#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/time.h>
#include <thread>

#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void test1(int code) {
	int b = WIFEXITED(code);
	int c = WIFSIGNALED(code);
	int d = WEXITSTATUS(code);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);

}

int main(int argc, char** argv) {
    test1(atoi(argv[1]));
}







