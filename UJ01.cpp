/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-02 09:34:50
* @Last Modified time: 2015-07-02 10:12:52
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define gc getchar
#define pc putchar
#define ll unsigned long long
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}


void scanint(ll &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
inline void writeInt (ll n)
    {
        ll N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        pc('\n');
    }
int main(){

	ll t;
	scanint(t);
	while(t--){
		ll a,b,n;
		scanint(a);
		scanint(b);
		scanint(n);
		ll g = gcd(a,b);
		ll l = (a*b)/g;
		g = (a + b)/g - 1;
		ll reps = n/g;
		n += reps;
		ll tr = (l/a) + (l/b);
		ll ans = (n/tr) * l;
		ll mula = ans/a + 1;
		ll mulb = ans/b + 1;
		ll count = n % tr;
		for (ll i = 0; i < count; ++i)
		{
			ll x = a * mula;
			ll y = b * mulb;
			if( x < y ){
				ans = x;
				mula++;
			}
			else
			{
				ans = y;
				mulb++;
			}
		}
		writeInt(ans);
	}
    return 0;
}