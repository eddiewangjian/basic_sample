#include <thread>
#include <iostream>
#include <stdlib.h>
#include <string>

#include <unistd.h>


void system_run(const char *command) {
    int ret = system(command);
    std::cout << "ret=" << ret << std::endl;
}

void detach_system_run(const char *command) {
    std::thread(&system_run, command).detach();
    while (true) {
        sleep(10);
        std::cout << "main alive" << std::endl;
    }
}

int main(int argc, char** argv) {
    //system_run("sh run_2s.sh");
    detach_system_run("sh run_2s.sh");
}





