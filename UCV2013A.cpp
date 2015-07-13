/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-06 13:57:40
* @Last Modified time: 2015-07-08 17:07:27
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;
const int m = 1000000007;
ll modexp(ll b, ll e){
	ll c = 1;
	b = b % m;
	while(e){
		if(e & 1){
			c = c * b;
			if(c > m)
				c = c%m;
		}
		e /= 2;
		b = b * b;
		if(b > m)
			b = b % m;
	}
	return c%m;
}
int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){
	int n,l;
	do{
		scanf("%d %d",&n,&l);
		if(n==0 && l == 0)
			break;
		else
		{
			ll sum = 0;
			for (int i = 1; i <= l; ++i)ss
			{
				sum += modexp(n,i);
				if(sum > m)
					sum %= m;
			}
				
			printf("%lld\n",sum);
		}
	}while(true);
    return 0;
}