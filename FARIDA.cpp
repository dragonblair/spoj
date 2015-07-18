#include <iostream>
#include <cstdio>
#define ll long long
#define sc(i) scanf("%d",&i)
using namespace std;

int max(int a,int b) { return a > b ? a : b;}

int main(int argc, char const *argv[])
{
	int t;
	sc(t);
	for(int f = 1; f <= t; ++f)
	{
		ll n;
		scanf("%lld",&n);
		if(n == 0)
			printf("Case %d: 0\n",f);
		else
		{
			ll a[n];
			for (int i = 0; i < n; ++i)
			{
				scanf("%lld",&a[i]);
			}
			ll dp[n];
			dp[0] = a[0];
			dp[1] = max(a[0],a[1]);
			for (int i = 2; i < n; ++i)
			{
				dp[i] = max(dp[i-2]+a[i],dp[i-1]);
			}
			printf("Case %d: %lld\n",f,dp[n-1]);
			}
		
	}
	return 0;
}