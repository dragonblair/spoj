/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-18 19:05:11
* @Last Modified time: 2015-06-19 16:38:48
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;
const int  p1 = 10627;
const int  p2 = 941;
const int m = p1 * p2;
int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}
long long modexp(long long b, long long e, long long p){
	long long c = 1;
	b = b % p;
	while(e){
		if(e & 1){
			c = ( c * b ) % p;
		}
		e /= 2;
		b = ( b * b) % p;
	}
	return c;
}
long long ncr(int n , int r){
	if( r > n )  
		return -1;

	long long nr = 1;
	long long dr = 1;

	for(int i = 0; i < r; ++i)
		nr = (nr * (n-i)) % m;
	for(int i = 1; i <= r; ++i)
		dr = (dr * i) % m;

	long long a1 = (nr * modexp(dr,p1-2,p1)) % p1;
	long long a2 = (nr * modexp(dr,p2-2,p2)) % p2;

	long long ans = 0;
	for(ans = m; ; ans--){

		if(ans % p1 == a1 && ans % p2 == a2)
			return ans;
		if(ans == 0)
			break;
	}
	return ans;
}


int main(){
	int n,r;
	cin>>n>>r;
	if(n == 0 && r == 0)
		cout<<1<<endl;
	else if(n == 1 && r == 0)
		cout<<0<<endl;
	else{
	n -= 1;
	r -= 1;
	if(n == 0 && r == 0)
		cout<<1<<endl;
	else
		cout<<ncr(n,r)<<endl;
	}
    return 0;
}