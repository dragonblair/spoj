/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-04 14:59:12
* @Last Modified time: 2015-07-04 15:41:53
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define ull unsigned long long
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ull n,k,m;
		scanf("%lld %lld %lld",&n,&k,&m);
		if(n > m)
			printf("0\n");
		else
		{
			float ans = (log(m) - log(n))/log(k);
			printf("%d\n",(int)ans);
		}
	}
    return 0;
}