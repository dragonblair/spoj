#include <stdio.h>
#include <iostream>
using namespace std;

long long calc(long long n, long long k){
	
	int f = ((n-k) & ((k-1) / 2));
	if( f == 0)
		return 1;
	else
		return 0;
}
int main(int argc, char const *argv[])
{
	int d;
	cin>>d;
	long long m,n;

	while(d--){
		cin>>n>>m;
		cout<<calc(n,m)<<endl;
	}
	return 0;
}