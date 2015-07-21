/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-20 21:54:04
* @Last Modified time: 2015-07-21 11:02:17
* @Solution to Problem : http://www.spoj.com/problems/UJ01/POWFIB.cpp
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#define ull unsigned long long
#define ll long long
#define sci(i) scanf("%d",&i)
#define scl(i) scanf("%ld",&i)
#define scll(i) scanf("%lld",&i)
#define gc getchar
#define pc putchar
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)
#define MAX 10000000

int nfibo[10] = {4,6,7,9,10,11,12,14,15,16};
using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        pc('\n');
    }
int fibo[MAX+1];
const int m = 1000000007;
ull modexp(ull b, ull e){
	ull c = 1;
	b = b % m;
	while(e){
		if(e & 1){
			c = ( c * b );
			if( c > m)
				c %= m;
		}
		e /= 2;
		b = ( b * b);
		if(b > m)
			b%=m;
	}
	return c;
}
int find_not_fibo(int n)
{
	if(n <= 10)
		return nfibo[n-1];
	int ans = n;
	int i  = 2;
	while(fibo[i] <= ans)
	{
		i++;
		ans++;
	}
	if(fibo[i] == ans+1)
		return ans+2;
	return ans+1;
}
void precompute()
{
	bool isfirst = true;
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= MAX; ++i)
	{
		fibo[i] = (fibo[i-1] + fibo[i-2]);
		
		if(fibo[i] > m)
			fibo[i] %= m;
		
	}
}
int main(){
	precompute();
	int t;
	scanint(t);
	
	while(t--)
	{
		int n;
		scanint(n);
		//printf("%d %d\n",find_not_fibo(n),fibo[n-1]);
		writeInt(modexp(find_not_fibo(n),fibo[n-1]));
	}
    return 0;
}