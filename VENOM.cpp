/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-19 20:59:11
* @Last Modified time: 2015-06-20 11:02:02
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

#define pc putchar
#define gc getchar

void scanint(long long &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

using namespace std;

long long min (long long a, long long b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}


long long calcAns(long long h, long long p, long long a)
{

	long long out = a*2 - 3 * p;
	long long in = p*p + 4*p*(2*h - 3*a) + 4*a*a;
	if(in < 0)
		return 1;
	long double root = sqrt(in);

	root += out;

	root /= (2*p);

	//cout<<"bro rott "<<root<<endl;
	
	if(root < 0)
		return 1;
	long long ans = root;
	

	double f = root - ans;

	if( f == 0)
		return ans*2 + 1;
	return (ans+1)*2 + 1;
}
inline void writeInt (long long n)
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
int main(){

	long long t;
	scanint(t);
	while(t--){
		long long h,p,a;
		scanint(h);
		scanint(p);
		scanint(a);

		writeInt(calcAns(h,p,a));
	}
	system("pause");
    return 0;
}