#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;


int knapSack(int W,int wt_arr[], int val_arr[], int n){
	int val_dp[n+1][W+1];

	for(int i=0;i<=W;i++){
		val_dp[0][i] = 0;
	}

	for(int i=0;i<=n;i++){
		val_dp[i][0] = 0;
	}

	for(int i = 1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(j>=wt_arr[i-1]){
				val_dp[i][j] = max(val_dp[i-1][j], (val_arr[i-1] + val_dp[i-1][j - wt_arr[i-1]]) );
			}
			else{
				val_dp[i][j] = val_dp[i-1][j];
			}
		}	
	}

	return val_dp[n][W];
}

int main() 
{ 
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
}