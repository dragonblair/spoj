/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-22 14:29:32
* @Last Modified time: 2015-06-22 14:56:36
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define MAX 1000000
#define gc getchar
#define rep(i,n) for(int i = 0; i < n; i++)
#define pc(x) putchar(x)
using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

void scanint(long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
inline void writeInt (long n)
    {
        long N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        pc('\n');
    }

long long int cubes[MAX];
long long int m = 1000000003;
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
void precompute(){
	long long sum = 1;

	cubes[0] = 1;
	for(int i = 1; i < MAX; ++i)
	{
		sum  = ((sum % m) + modexp(i+1,3)) % m;
		cubes[i] = (sum + cubes[i-1]) % m; 
	}
	
		
}
int main(){

	precompute();
	long t;
	scanint(t);
	while(t--)
	{
		long n;
		scanint(n);
		writeInt(cubes[n-1] % m);
	}
    return 0;
}