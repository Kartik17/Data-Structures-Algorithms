#include <iostream>
using namespace std;

void swap(int* a, int* b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertion_sort(int arr[], int size){

	int min_index = 0;
	
	for(int i=1; i<size; i++){
		int j =i-1;
		
		while(j>=0){
			if(arr[j+1]<arr[j]){
				swap(&arr[j+1],&arr[j]);
				
			}
			j--;
		}

	}

}



int main(int argc, char const *argv[])
{
	
	int arr[] = { 12, 11, 13, 5, 6, 7, 19, 40, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,n);

    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
		}

}