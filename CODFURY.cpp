/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-26 14:12:45
* @Last Modified time: 2015-06-27 12:36:06
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define gc getchar

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
	int t;
	scanint(t);
	while(t--)
	{
		int p,m;
		scanint(p);
		scanint(m);
		int a[p];
		rep(i,p) scanint(a[i]);
		int pans = 0;
		int mans = 0;
		int cp = 0;
		int cm = 0;
		int j = 0;
		for (int i = 0; i < p; ++i)
		{
			if( j >= p)
				break;
			while (m >= a[j] && j < p){
				cp++;m -= a[j];cm += a[j];j++;
			}
			if (cp > pans){ 
				pans = cp; mans = cm;
			}
			else if(cp == pans && cm <= mans){
				pans = cp; mans = cm;
			}
			if (cp != 0){
				cp--; m += a[i]; cm -= a[i];
			}
			if(j == i)
				j++;
		}
		printf("%d %d\n",mans,pans);
	}
	return 0;
}