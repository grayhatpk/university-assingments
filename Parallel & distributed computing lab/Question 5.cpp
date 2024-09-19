#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::condition_variable cv;
std::mutex mtx;
bool x_turn = true;
int count = 0;

void print_x() {
    for (int i = 0; i < 5; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{ return x_turn; });
        std::cout << "X ";
        x_turn = false;
        cv.notify_all();
        ++count;
    }
}

void print_o() {
    for (int i = 0; i < 5; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{ return !x_turn; });
        std::cout << "O ";
        x_turn = true;
        cv.notify_all();
        ++count;
    }
}

int main() {
    std::thread t1(print_x);
    std::thread t2(print_o);

    t1.join();
    t2.join();

    std::cout << std::endl;
    std::cout << "Main program ends" << std::endl;

    return 0;
}