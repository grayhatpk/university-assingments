#include <iostream>
using namespace std;

void counting_sort_in_place(int A[], int k, int size) {
    // Determine the maximum value in the array
    int max_value = 0;
    for (int i = 0; i < size; i++) {
        max_value = max(max_value, A[i]);
    }

    // Create an auxiliary array C of size k + 1 to store the counts of each element
    int C[max_value + 1];
    for (int i = 0; i <= max_value; i++) {
        C[i] = 0;
    }

    // Count the occurrences of each element in array A
    for (int i = 0; i < size; i++) {
        C[A[i]]++;
    }

    // Modify the array C to reflect the correct positions of the elements
    for (int i = 1; i <= max_value; i++) {
        C[i] += C[i - 1];
    }

    // Use array C as an index to place the elements in their correct positions in array A
    for (int i = size - 1; i >= 0; i--) {
        C[A[i]]--;
        A[C[A[i]]] = A[i];
    }
}

int main() {
    int A[] = {5, 2, 4, 1, 3};
    int k = 5;
    int size = sizeof(A) / sizeof(A[0]);

    counting_sort_in_place(A, k, size);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
