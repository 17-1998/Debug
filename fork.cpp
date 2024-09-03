#include <iostream>
#include <unistd.h>  // For fork(), getpid(), and getppid()

int main() {
    // Create a new process
    pid_t pid = fork();

    // Check if fork() failed
    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }

    // Fork succeeded
    if (pid == 0) {
        // Child process
        std::cout << "Child process:" << std::endl;
        std::cout << "Child PID: " << getpid() << std::endl;
        std::cout << "Parent PID: " << getppid() << std::endl;
    } else {
        // Parent process
        std::cout << "Parent process:" << std::endl;
        std::cout << "Parent PID: " << getpid() << std::endl;
        std::cout << "Child PID: " << pid << std::endl;
    }

    return 0;
}
