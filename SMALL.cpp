/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-29 14:56:19
* @Last Modified time: 2015-06-29 17:26:51
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define long long long
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(long  a, long  b){ return (b==0)? a : gcd(b, a%b);}
const int seive = 10010;
int isprime[seive];
int sq[seive];
long p = 1000000007;
void calcPrimes(){
		for(int i = 2; i * i < seive; i++){
			if(!isprime[i]){
				for(int j = i*i ; j < seive; j += i)
				{
					isprime[j] = true;
				}
			}
		}
		for (int i = 2; i < seive; ++i)
		{
			if(!isprime[i])
			{
				for (int j = i; j<seive ; j *= i ) {
                    sq[j] = i;
                }
			}
		}
	}
long lcm(int n)
{
	 	if(n == 1)
            return 1;
        else if(sq[n] != 0)
            return (lcm(n-1) * sq[n]) % p;
        else
            return lcm(n-1);
}
int main(){
	calcPrimes();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",lcm(n));
	}
    return 0;
}