#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

// Function to sort an array in ascending order
void sortAscending(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

// Function to sort an array in descending order
void sortDescending(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), std::greater<int>());
}

int main() {
    // Initialize arrays
    std::vector<int> ascendingArray = {5, 2, 9, 1, 5, 6};
    std::vector<int> descendingArray = {3, 8, 2, 4, 7, 5};

    // Create threads for sorting
    std::thread thread1(sortAscending, std::ref(ascendingArray));
    std::thread thread2(sortDescending, std::ref(descendingArray));

    // Wait for both threads to complete
    thread1.join();
    thread2.join();

    // Print sorted arrays
    std::cout << "Sorted array in ascending order: ";
    for (const auto& num : ascendingArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted array in descending order: ";
    for (const auto& num : descendingArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
