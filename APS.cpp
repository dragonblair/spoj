/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-06 15:10:43
* @Last Modified time: 2015-07-06 15:24:08
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;
const int seive = 10000000;
int primes[seive+1];
unsigned long long result[seive+1];
int calcPrimes(){
		primes[0] = 0;
		primes[1] = 0;
		for(long long i = 2; i <= seive; i++){
			if(!primes[i]){
				primes[i] = i;
				for(long long j = i ; j * i <= seive; j++)
				{
					if(!primes[j*i]) primes[j*i] = i;
				}
			}
		}
		for (int i = 2; i <= seive; ++i)
		{
			result[i] = result[i-1] + (long)primes[i]; 
		}
}
int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){
	calcPrimes();
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",result[n]);
	}
    return 0;
}