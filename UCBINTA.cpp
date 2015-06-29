/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-24 14:15:42
* @Last Modified time: 2015-06-24 15:34:28
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define gc getchar
#define pc(x) putchar(x);
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;
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
        pc(' ');
    }
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){

	int n;
	scanint(n);
	int a[n][n];
	int sol[n];

	rep(i,n)
		rep(j,n)
			scanint(a[i][j]);
	
	if(n == 2)
	{
		printf("%d %d\n",a[0][1]/2,a[0][1]/2);
	}
	else
	{
			int x = a[0][2];
			int y = a[1][2];

			int a1 = a[0][1];
			int b1 = x-y;

			sol[0] = (a1+b1)/2;
			sol[1] = (a1-b1)/2;
		writeInt(sol[0]);
		writeInt(sol[1]);
		for (int i = 2; i < n; ++i)
		{
			writeInt(a[0][i] - sol[0]);
		}
		pc('\n');
	}
    return 0;
}