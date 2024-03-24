#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;}
  
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
  cout << array[i] << " ";
  cout << endl;
}

//function to partition the array
int partition(int array[], int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }}
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    int part = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, part - 1);

    // recursive call on the right of pivot
    quickSort(array, part + 1, high);
  }
}

int main() {
	
  int size = 5000;	 	
  int data[size];
  
  for(int i = 0;i<size;i++)	
		data[i] = rand();
	
  cout << "Unsorted Array: \n";
  printArray(data, size);
  
  quickSort(data, 0, size - 1);
  
  cout << "Sorted array in ascending order: \n";
  printArray(data, size);
}