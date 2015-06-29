#include <stdio.h>
#include <iostream>
using namespace std;
const int m = 1000000007;
#define rep(i,n) for(int i = 0; i < n; i++)
long long modexp(long long b, long long e){
	long long c = 1;
	b = b % m;
	while(e){
		if(e & 1){
			c = ( c * b ) % m;
		}
		e /= 2;
		b = ( b * b) % m;
	}
	return c;
}
int main(int argc, char const *argv[])
{
	long n,k;
	do{
		cin>>n>>k;
		if(n == 0 && k == 0)
			return 0;
		else{
			long ans = (((modexp(n-1,k) + modexp(n-1,n-1)) << 1) + modexp(n,n) + modexp(n,k));
			cout<<(ans%m)<<endl; 		
		}
	}while(true);
	return 0;
}