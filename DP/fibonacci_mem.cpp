#include <iostream>
using namespace std;

int fib(int a,int dp[]){
	if(a == 0 or a == 1){
		dp[a] = a;
		return dp[a];
	}
	else if(dp[a] != -1){
		return dp[a];
	}
	dp[a] = fib(a-1,dp) + fib(a-2,dp);
	return dp[a];
}


int main(int argc, char const *argv[])
{	

	int n = 10;
	static int* dp = new int[n+1];
	for(int i = 0 ;i<=n;i++){
		dp[i] = -1;
	}
	
	cout<<fib(n,dp)<<endl;

	for(int i =0 ;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	return 0;
}