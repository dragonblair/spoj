/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-26 14:12:45
* @Last Modified time: 2015-06-30 11:19:59
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define gc getchar
#define ll long long
#define pc(x) putchar(x);
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
inline void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        
    }
int main(int argc, char const *argv[])
{
	
		int p;
		ll m;
		scanint(p);
		scanf("%lld",&m);
		int a[p];
		rep(i,p) scanint(a[i]);
		ll mans = 0;
		ll cm = 0;
		int j = 0;
		for (int i = 0; i < p; ++i)
		{
			if( j >= p)
				break;
			while (m >= a[j] && j < p){
				m -= a[j];cm += a[j];j++;
			}
			if (cm > mans){ 
				mans = cm;
			}
			if (j != 0){
				m += a[i]; cm -= a[i];
			}
			if(j == i)
				j++;
		}
		printf("%lld\n",mans);
	
	return 0;
}