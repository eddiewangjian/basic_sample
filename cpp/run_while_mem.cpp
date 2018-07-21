#include <sys/mman.h>  
#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
  
#define BUF_SIZE 100  
  
int main(int argc, char** argv)  
{  
	int *p = new int[10000000] ();
	p[0] = '1';
	while (true) {
		sleep(1);
	}
    return 0;  
} 
