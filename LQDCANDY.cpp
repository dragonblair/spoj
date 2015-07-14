/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-14 04:09:16
* @Last Modified time: 2015-07-14 04:51:49
* @Solution to Problem : http://www.spoj.com/problems/UJ01/LQDCANDY.cpp
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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

ull N = 10e18;
ull *sum;
int size;
void precompute()
{
	size = ceil(log(N)/log(2));
	sum = new ull[size];
	sum[0] = 1;
	loop(i,1,size)
	{
		sum[i] = sum[i-1] * 2;
	}
}

int main(){
	precompute();
	ll t;
	scll(t);
	while(t--)
	{
		ull n;
		scll(n);
		if(! (n & (n-1)))
			printf("%lld 0\n",n);
		else
		{
			int count = size-1;
			while(n < sum[count--]);
			count++;
			ull cur = 0;
			int f = count;
			while(f >= 0)
			{
				cur += sum[f]+cur > n ? 0 : sum[f];
				if(cur == n)
					break;
				f--;
			}
			if(f == -1) f = 0;
			printf("%lld %d\n",sum[count]*2,count-f+1);
		}
		
	}
    return 0;
}