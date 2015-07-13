/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-26 11:40:54
* @Last Modified time: 2015-07-05 11:42:28
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define gc getchar
#define rep(i,n) for(int i = 0; i < n; i++)
#define pc(x) putchar(x);
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
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
        pc('\n');
    }
const int seive = 1000000;
int maxi = -1;
int primes[seive+1];
bool isprimes[seive+1];
int steps[seive+1];
int dp[seive+1][13];
int calcPrimes(){
	primes[0] = 0;
	primes[1] = 0;
	for(int i = 2; i <= seive; ++i)
	{
		if(!isprimes[i])
		{
			for (int j = i; j <= seive; j += i)
			{
				if(j == i)
					primes[j] = false;
				else
					isprimes[j] = true;
					
					primes[j] += i;
			}
		}
	}
	steps[0] = 0;
	steps[1] = 0;
	for (int i = 2; i <= seive; ++i)
	{
		if(!isprimes[i])
			steps[i] = 1;
		else{
			int cur_step = 1;
			for (int x = primes[i]; isprimes[x] != false; x = primes[x],++cur_step);
			steps[i] = cur_step + 1;
		}
	}
	for (int i = 1; i <= 12; ++i)
	{
		for (int j = 2; j <= seive; ++j)
		{
			if(steps[j] == i)
				dp[j][i] = dp[j-1][i] + 1;
			else
				dp[j][i] = dp[j-1][i];
		}
	}
	
}

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){

	calcPrimes();
	int t;
	scanint(t);
	while(t--){
		int a,b,k;
		scanint(a);
		scanint(b);
		scanint(k);
		if(k > 12)
			printf("0\n");
		else
			printf("%d\n",dp[b][k] - dp[a-1][k]);
	}
}