#include <iostream>

using namespace std;

void maxHeapify(int arr[], int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {50,40,30,20,10,35,15};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printHeap(arr,n);

    maxHeapify(arr,2, n);

    cout << "Max heap: ";
    printHeap(arr, n);

    return 0;
}
