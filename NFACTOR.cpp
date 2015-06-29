/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-26 11:40:54
* @Last Modified time: 2015-06-26 13:36:22
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
int primes[seive+1];
bool isprimes[seive+1];
int nfactor[8][seive+1];
int calcPrimes(){

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
					
					primes[j]++;
			}
		}
	}
	for (int i = 1; i <= seive; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (primes[i] == j)
			{
				nfactor[j][i] = nfactor[j][i-1] + 1;
			}
			else
				nfactor[j][i] = nfactor[j][i-1];
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
		int a,b,n;
		scanint(a);
		scanint(b);
		scanint(n);
		if(n > 7)
			writeInt(0);
		else
			writeInt(nfactor[n][b] - nfactor[n][a-1]);
	}
}