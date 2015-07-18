/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-18 12:19:53
* @Last Modified time: 2015-07-18 12:23:30
* @Solution to Problem : http://www.spoj.com/problems/UJ01/ACPC11B.cpp
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <climits>
#include <set>
#define ull usigned long long
#define ll long long
#define sci(i) scanf("%d",&i)
#define scl(i) scanf("%ld",&i)
#define scll(i) scanf("%lld",&i)
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){
	int t;
	sci(t);
	while(t--)
	{
		int m,n;
		sci(m);
		int a[m];
		rep(i,m) sci(a[i]);
		sci(n);
		int b[m];
		rep(i,n) sci(b[i]);
		int min = INT_MAX;
		rep(i,m)
		rep(j,n)
		{
			int diff = abs(a[i]-b[j]);
			if(diff < min)
				min = diff;
		}
		printf("%d\n",min);
	}
    return 0;
}