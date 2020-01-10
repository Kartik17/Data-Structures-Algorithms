#include <iostream>
using namespace std;

int fib(int n){
	int f0 = 0;
	int f1 = 1;

	int f;
	if(n == 1){
		return f1;
	}

	else{
		for(int i=1;i<n;i++){

			f = f0 + f1;
			f0 = f1;
			f1 = f;
		}
	}

	return f;
}

int main(int argc, char const *argv[])
{	

	cout<<fib(14);
	return 0;
}