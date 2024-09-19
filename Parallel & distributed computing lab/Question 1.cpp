#include <iostream>
#include <thread>

// Function to print numbers from 1 to 5
void printNumbers() {
    for (int i = 1; i <= 5; i++) {
        std::cout << i <<"\t";
    }
}

// Function to print squares of numbers from 1 to 5
void printSquares() {
    for (int i = 1; i <= 5; i++) {
        std::cout << i * i <<"\t";
    }
}

int main() {
    // Create two threads
    std::thread t1(printNumbers);
    std::thread t2(printSquares);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    return 0;
}