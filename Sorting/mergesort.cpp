#include <iostream>
using namespace std;

void swap(int* a, int* b){

	int temp = *a;
	*a = *b;
	*b = temp;
}


void merge(int l, int m, int r, int arr[]){

	int n1 = m - l + 1;
	int n2 = r - m;
	int i,j; 

	int left_arr[n1];
	int right_arr[n2];


	for(i=0;i<n1;i++){
		left_arr[i] = arr[l+i];
	}

	for(j=0;j< n2;j++){
		right_arr[j] = arr[m+j+1];
	}

	i = 0;
	j = 0;

	int k = l;
	while((i<n1) and (j<n2)){
		if(left_arr[i]>right_arr[j]){
			arr[k] = right_arr[j];
			j++;
		}

		else{
			arr[k] = left_arr[i];
			i++;
		}

		k++;
	}

	while(i<n1){
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	while(j<n2){
		arr[k] = right_arr[j];
		j++;
		k++;	
	}

}


void mergesort(int arr[], int l, int r){

	if(l<r){
		int m_index = (r+l)/2;
		
		mergesort(arr,l,m_index);
		mergesort(arr,m_index+1,r);

		merge(l,m_index,r,arr);

		}
}


int main(int argc, char const *argv[])
{
	
	int arr[] = { 12, 11, 13, 5, 6, 7, 19, 40, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
		}

}