#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/time.h>
#include <thread>

#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void son_do_sth() {
    int count = 3;
    while(count > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        printf("son_do_sth: %d\n", count);
        count--;
    }
}


// fork 子进程
// 内存复制
int test1() {
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
		// exit(333);
		return 22;
    } else {
        // 主进程分支
        printf("main said: fork success ret=%d\n", ret_pid);
		pid_t my_pid = getpid();
		printf("son said: my_pid=%d child_pid=%d\n", my_pid, ret_pid);
        son_do_sth();
        //exit(444);
		return 33;
    }

	//打印各个进程的离开时间
    struct timeval time;
    int ret = gettimeofday(&time, NULL);
    printf("%06d\n", time.tv_usec);

}

// vfork 子进程
// 内存共享；先return的进程，会破坏栈结构，导致后边进程退出失败，先结束的应该exit；
int test2() {
    pid_t main_pid = getpid();
    cout << "main_pid: " << main_pid << endl;

	int shared_var = 1;

    pid_t ret_pid = vfork();
    if (ret_pid < 0) {
        printf("fork failed ret=%d\n", ret_pid);
    }
    else if(ret_pid == 0) {
        //子进程分支
        printf("son said: fork success ret=%d\n", ret_pid);
        son_do_sth();
		shared_var += 1;
    } else {
        // 主进程分支
        printf("main said: fork success ret=%d\n", ret_pid);
        //exit(444);
		shared_var += 1;
    }

    printf("shared_var=%d\n", shared_var);

	exit(0);
}


int main(int argc, char** argv) {
    int res = test2();
    printf("ret_code=%d\n", res);

}







