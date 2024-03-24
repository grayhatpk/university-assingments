#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;


void heapify(int arr[], int n, int i)
{
	int largest = i; // make the index i element to largest
	int l = 2 * i + 1; // left node
	int r = 2 * i + 2; // right node
	 
	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than the root
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root swap the child with the root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}


void heapSort(int arr[], int n)
{
	
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
	
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	int n = 5000;
	int array[n];
	
	for (int i = 0;i<n;i++)	
		array[i] = rand();
		
	cout<<"Initital Array: \n";
	printArray(array,n);
		
	for(int i=n/2 -1;i>=0;i--){
		heapify(array,n,i);
	}

	heapSort(array, n);

	cout << "\nSorted array is \n";
	printArray(array, n);
	
	auto end = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds\n";

return 0;
}
