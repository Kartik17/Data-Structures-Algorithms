#include <iostream>
using namespace std;

void swap(int* a, int* b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int arr[], int size){

	int min_index = 0;
	for(int i=-1; i<size-1; i++){
		min_index = i+1;
		for(int j= i+1; j<size; j++){
			if(arr[j]<arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[i+1],&arr[min_index]);
		cout<< min_index<<endl;
	}

}



int main(int argc, char const *argv[])
{
	
	int arr[] = { 12, 11, 13, 5, 6, 7, 19, 40, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr,n);

    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
		}

}