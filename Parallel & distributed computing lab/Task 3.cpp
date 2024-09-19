#include <iostream>
#include <thread>

int main() {
    // Create thread 1 using a lambda expression
    std::thread t1([&]() {
        std::cout << "Hello from Thread 1" << std::endl;
    });

    // Create thread 2 using a lambda expression
    std::thread t2([&]() {
        std::cout << "Hello from Thread 2" << std::endl;
    });

    // Wait for both threads to finish
    t1.join();
    t2.join();

    std::cout << "Main program ends" << std::endl;

    return 0;
}