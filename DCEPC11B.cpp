/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-22 12:30:01
* @Last Modified time: 2015-06-26 10:24:16
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define long long long
#define loop(i,x,y) for(int i = x; i < y; ++i)
#define gc getchar
#define rep(i,n) for(int i = 0; i < n; i++)
#define pc(x) putchar(x);
using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

long modexp(long b,long e,long m){
	long c = 1;

	while(e){
		if(e & 1){
			c = ( c * b );
			if(c > m)
				c = c % m;
		}
		e /= 2;
		b = ( b * b);
		if(b > m)
			b = b%m;
	}
	return c % m;
}
long factmod(long n, long p)
{
	if( n >= p )
		return 0;
	long ans = 1;

	if(n > 3*p/4)
	{
		for (int i = n+1; i < p; ++i)
		{
			ans = (ans * i);
			if(ans > p)
				ans = ans % p;
		}
		ans = -1 * modexp(ans,p-2,p) + p;
		return ans % p;
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			ans = (ans * i);
			if(ans > p)
				ans = ans % p;
		}
		return ans % p;
	}
	
}
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
int main(){

	int t;
	scanf("%d",&t);
	while(t--){
		long n,p;
		scanint(n);
		scanint(p);
		writeInt(factmod(n,p));
	}
    return 0;
}