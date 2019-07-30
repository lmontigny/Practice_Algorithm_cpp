/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
using namespace std; 

int swap(int* a, int* b){
	int* tmp = a;
	a = b;
	b = tmp;
}

int partition (int arr[], int low, int high) 
{ 
	int p = high;
	int i = low;
	int j = high;

	while(i<j){
		// Smaller on the left side of the pivot = dont touch it, go to the next
		while(arr[i]<=arr[p] && i<high) 
			i++;
		// Bigger than pivot, take the next one starting from the right
		while(arr[j]>arr[p]) 
			j--;
		if(i<j)
			swap(arr[i], arr[j]);
	}
	return p;
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	quickSort(arr, 0, n - 1); 
	cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 
