/*

Longest Increasing SubSequence

*/

#include <iostream>
using namespace std;

void lis(int arr[],int n){
	int L[n];
	for(int i=0;i<n;i++){
		L[i] = 1;
		int max = 0;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				if(L[j]>max){
					max = L[j];
				}
			}
		}
		L[i] = 1 + max;

	}

	for(int i=0;i<n;i++){
		cout<<L[i]<<", ";
	}


}

int main(int argc, char const *argv[])
{	
	int arr[] = {3, 10, 2, 1, 5, 6, 9};
	lis(arr,(sizeof(arr)/sizeof(*arr)));
	return 0;
}