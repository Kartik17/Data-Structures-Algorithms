#include <iostream>
using namespace std;


/*

Crictical Function --> heapify

Main idea --> start at the (n/2 -1) index till 0th index.
At each index, taking the index as the root node check if they form a heap.
Here, we are checking for Max heap, which has the following cond:
root > (leftChild and righChild)

*/

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int leftChild(int i){return 2*i +1;}

int rightChild(int i){return 2*i +2;}

int parent(int i){return (i-1)/2;}

void heapify(int arr[], int i, int heap_size){

	int maxChildindex = -1;

	while(leftChild(i)<heap_size){
		maxChildindex = leftChild(i);
		if((arr[leftChild(i)]<arr[rightChild(i)]) & (rightChild(i)<heap_size)){
			maxChildindex = rightChild(i);
		}

		if(arr[i]<arr[maxChildindex]){
			swap(arr[i],arr[maxChildindex]);
			i = maxChildindex;
		}
		else{
			return;
		}

	}


}

void heapSort(int arr[], int size){

	for(int i = size/2 -1; i >=0; i--){
		heapify(arr,i,size);
	}

	int temp;
	for(int i = size-1; i >=0; i--){		
		swap(arr[0],arr[i]);
		heapify(arr,0,i);

	}

	for(int j = 0; j <size; j++){
			cout<<arr[j]<<" ";
		}

	
	
}


int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7, 19, 40, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    heapSort(arr, n); 
} 