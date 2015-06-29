#include <stdio.h>
#include <iostream>
#include <cmath>
#define gc getchar_unlocked
#define rep(i,n) for(int i = 0; i < n; i++)
#define pc(x) putchar_unlocked(x);
using namespace std;
void scanint(long &);
inline void writeInt(int);
long gcd(long a, long b){
	do{
		if( a < 0 || b < 0)
			return 1;
		else if( a == b )
			return a;
		else if( a > b)
			a = a - b;
		else
			b = b - a;

	}while(true);
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	long a,b;
	while(t--){
		scanint(a);
		scanint(b);
		long count = 0;
		long cur_gcd = gcd(a,b);
		if(cur_gcd == 1)
			writeInt(1);
		else{

			for (int i = 1; i * i  <= cur_gcd; ++i)
			{
				if( cur_gcd % i == 0)
				{
					if( cur_gcd / i == i)
						count += 1;
					else
						count += 2;
				}
			}
		writeInt(count);
		}
	}
	return 0;
}




void scanint(long &x)
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