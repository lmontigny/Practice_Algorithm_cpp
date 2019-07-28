#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void countingSort(int arr[] ,int n, int range){
	int count[range] = {0};
	int res[n];

	// Count nb occurence
	for(int i=0;i<n;i++){
		++count[arr[i]];
	}

	// Prefix sum
	// --> Contain the position of the element in output array
	for(int i=1;i<range;i++){
		count[i] += count[i-1];
	}

	// Output array
	// --> alpha = count[arr[i] is the position of arr[i] in output array
	// res[alpha] takes the arr[i] element
	// res[alpha-1] to start from res[0] not res[1]
	for(int i=0;i<n;i++){
		res[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}

	// Return array
	for(int i=0;i<n;i++){
		arr[i] = res[i];
	}
}

void print(int arr[],int n){
	cout<<"array : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
	cout<<endl;
}


int main() {
	// your code goes here
	int arr[]={5, 4, 1, 2, 7, 1, 2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int RANGE=9;

	print(arr,n);

	countingSort(arr,n,RANGE);

	print(arr,n);

	return 0;
}
