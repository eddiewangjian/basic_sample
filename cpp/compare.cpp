#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <unistd.h>
#include <sys/time.h>

#include <time.h>


using namespace std;


void test1() {
	int a = 3;
	unsigned int b = 3;
	if (a == b) {
		printf("a==b");
	}
}

int main(int argc, char** argv) {
    test1(); 
}







