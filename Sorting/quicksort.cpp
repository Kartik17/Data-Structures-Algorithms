#include <iostream>
using namespace std;


/*

Concept of Pivot, followed by divide and conquer using recursion.
Array --> { 12, 11, 13, 5, 6, 7, 19, 40, 2 }

First run:
Pivot --> 2
{ 12, 11, 13, 5, 6, 7, 19, 40, 2 }
Partition --> 0

{ 2, 11, 13, 5, 6, 7, 19, 40, 12 }


{ 2, 11, 5, 6, 7, 12, 19, 40, 13 }


{2,5,6},{7,11} || {12},{13,19,40}

{2,5}{6}

{2}{5}

*/


void swap(int* a, int* b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

int partition(int arr[],int first, int last){

	int j = (first-1);

	for(int i = first;i<last;i++){

		if(arr[i]<=arr[last]){
			j++;
			swap(&arr[j],&arr[i]);
		}


	}
	j++;
	swap(&arr[last],&arr[j]);

	return j;
}


void quicksort(int arr[], int first, int last){

	if(first<last){
		int k = partition(arr,first,last);
		cout<<k<<endl;
		quicksort(arr,first,k-1);
		quicksort(arr,k,last);

	}

}


int main(int argc, char const *argv[])
{
	int arr[] = { 12, 11, 13, 5, 6, 7, 19, 40, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
    }

	

	return 0;
}
