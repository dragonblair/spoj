/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-18 11:59:52
* @Last Modified time: 2015-07-18 12:07:57
* @Solution to Problem : http://www.spoj.com/problems/UJ01/AMR11E.cpp
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
#define MAX 3000
using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}
int factors[MAX+1];
bool isprime[MAX+1];
void precompute()
{
	for (int i = 2; i <= MAX; ++i)
	{
		if(!isprime[i])
		for (int j = i; j <= MAX; j+=i)
		{
			if(j != i)
				isprime[j] = true;
			factors[j]++;
		}
	}
}

int main(){
	precompute();
	int t;
	sci(t);
	while(t--)
	{
		int n;
		sci(n);
		int i;
		for (i = 2;i <= MAX; ++i)
		{
			if(factors[i] >= 3)
			{
				n--;
				if(n == 0){
					printf("%d\n",i);
					break;
				}
			}
		}
		
	}
    return 0;
}