#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // mutex for protecting shared variable
int sharedVariable = 0; // shared variable

void incrementVariable() {
    for (int i = 0; i < 100; i++) {
        std::lock_guard<std::mutex> lock(mtx); // acquire lock
        sharedVariable++; // increment shared variable
    }
}

int main() {
    std::thread t1(incrementVariable); // create thread 1
    std::thread t2(incrementVariable); // create thread 2

    t1.join(); // wait for thread 1 to finish
    t2.join(); // wait for thread 2 to finish

    std::cout << "Final value of shared variable: " << sharedVariable << std::endl;

    return 0;
}