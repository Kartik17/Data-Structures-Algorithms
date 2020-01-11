/*

Longest Common SubSequence

*/

#include <iostream>
#include <algorithm>
#include<bits/stdc++.h> 
using namespace std;



int lcs(char arr1[], char arr2[], int size1, int size2){
	int L[size1+1][size2+1];
	
	for(int i=0; i<= size1; i++){
		L[i][0] = 0;
	}

	for(int i=0; i<= size2; i++){
		L[0][i] = 0;
	}

	for(int i=1;i <=size1;i++){
		for(int j=1;j<=size2;j++){
			
			if(arr1[i] == arr2[j]){
				L[i][j] = 1 + L[i-1][j-1];
			}
			else{
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}

			//cout<<L[i][j]<<", ("<<i<<","<<j<<")"<<endl;
		}
	}

	return L[size1][size2];
}


int main()  
{  
    char X[] = "BCDBCDAV";  
    char Y[] = "ABECBABV";  
      
    int m = strlen(X);  
    int n = strlen(Y);  
      
    cout << "Length of LCS is " 
         << lcs( X, Y, m, n );  
      
    return 0;  
}  