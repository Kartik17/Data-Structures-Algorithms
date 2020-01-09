#include <iostream>
using namespace std;


void swap(int* a, int* b){
	int temp = *b;
	*b = *a;
	*a = temp;
}


void bubblesort(int arr[],int size){

	while(true){
		int swap_count = 0;
		for(int i=0;i<size-1;i++){
			
			if(arr[i]>arr[i+1]){
				swap(&arr[i],&arr[i+1]);
				swap_count++;

				}
		}

		if(swap_count == 0){
			return;
		}

	}
}


int main(int argc, char const *argv[])
{
	int arr[] = { 12, 11, 13, 5, 6, 7, 19, 40, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr,n);

    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
    }
}