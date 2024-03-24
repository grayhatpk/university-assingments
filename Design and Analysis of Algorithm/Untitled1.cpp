#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	
	int length = 50000;
	
	int A[length],key,j;
	
	for (int i=0; i<length; i++){
		A[i] = rand() % 1000;
		cout<<A[i]<<" ";
	}
	
	
	for (int i = 0; i<length; i++){
		
		key = A[i];
		
		j = i-1;
		
		while (j >= 0 && A[j]>key){
			
			A[j+1] = A[j];
			j=j-1;
			
		}
	A[j+1] = key;	
	}
	cout<<"\n\n------After Sorting--------\n\n";
	for (int j = 0; j<length; j++){
		cout<<A[j]<<" ";
	}
	
}