#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// for file operate
#include <fcntl.h>

// for mmap
#include <sys/mman.h>

// for fork
#include <unistd.h>

using namespace std;

const int BUFFER_SIZE = 100;


// fork 子进程,父子进程使用父进程产出的mmap来通信
// 通信
int test1() {
    cout << "create mmap" << endl;

    char* p_map;
    p_map = (char*)mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    pid_t main_pid = getpid();
    cout << "main_pid: " << main_pid << endl;

    pid_t ret_pid = fork();
    if (ret_pid < 0) {
        printf("fork failed ret=%d\n", ret_pid);
    }
    else if(ret_pid == 0) {
        //子进程分支
        printf("son said: fork success ret=%d\n", ret_pid);
		pid_t my_pid = getpid();
		pid_t main_pid = getppid();
		printf("son said: my_pid=%d father_pid=%d\n", my_pid, main_pid);
        printf("son addr:%ld\n", (long)p_map);
        sprintf(p_map, "%s", "hi, father, i am your son");
        munmap(p_map, BUFFER_SIZE); 

		// exit(333);
    } else {
        // 主进程分支
        printf("main said: fork success ret=%d\n", ret_pid);
		pid_t my_pid = getpid();
		printf("son said: my_pid=%d child_pid=%d\n", my_pid, ret_pid);
        sleep(2);
        printf("father get msg:%s\n", p_map);
        printf("father addr:%ld\n", (long)p_map);
    }

    return 0;
}


// 子进程控制父进程产出mmap
int test2() {
    cout << "create mmap" << endl;

    char* p_map_comm;
    p_map_comm = (char*)mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    pid_t main_pid = getpid();
    cout << "main_pid: " << main_pid << endl;

    pid_t ret_pid = fork();
    if (ret_pid < 0) {
        printf("fork failed ret=%d\n", ret_pid);
    }
    else if(ret_pid == 0) {
        //子进程分支
        printf("son said: fork success ret=%d\n", ret_pid);
		pid_t my_pid = getpid();
		pid_t main_pid = getppid();
		printf("son said: my_pid=%d father_pid=%d\n", my_pid, main_pid);
        printf("son addr:%ld\n", (long)p_map_comm);
        sprintf(p_map_comm, "%s", "a.txt");
        sleep(3);
        printf("son get msg:%s\n", p_map_comm);

        //munmap(p_map_comm, BUFFER_SIZE); 

		// exit(333);
    } else {
        // 主进程分支
        printf("main said: fork success ret=%d\n", ret_pid);
		pid_t my_pid = getpid();
		printf("son said: my_pid=%d child_pid=%d\n", my_pid, ret_pid);
        sleep(2);
        printf("father get msg:%s\n", p_map_comm);
        int fd = open(p_map_comm, O_RDONLY);
        
        int filesize = lseek(fd, 0, SEEK_END) ;
        cout << filesize << endl;
        char* p_map;
        p_map = (char*)mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0);
        printf("father read txt:%s\n", p_map);
        p_map_comm = p_map;
        sleep(3);


        printf("father addr:%ld\n", (long)p_map_comm);
    }

    return 0;

}



int main(int argc, char** argv) {
    int res = test2();
    printf("ret_code=%d\n", res);

}







