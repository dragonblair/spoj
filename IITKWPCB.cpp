/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-04 20:26:10
* @Last Modified time: 2015-07-04 20:42:02
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
		ull n;
		scanf("%lld",&n);
		ull f = floor(n/2);
		if(n == 2)
			printf("1\n");
		else if(n & 1)
			printf("%lld\n",f);
		else if(f & 1)
			printf("%lld\n",f-2);
		else
			printf("%lld\n",f-1);
	}
    return 0;
}