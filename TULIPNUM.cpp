/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-17 13:58:30
* @Last Modified time: 2015-06-17 14:53:37
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>

#define gc getchar_unlocked
#define pc putchar_unlocked
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

#define MAX 100002

int pre[MAX];

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

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

int main(){

	int t;
	scanint(t);
	rep(f,t){
		int n,q;

		scanint(n);
		scanint(q);

		int a[n];
		
		rep(i,n){

		 scanint(a[i]);
		 if ( i == 0 )
		 	pre[i] = 1;
		 else
		 {
		 	if(a[i] == a[i-1])
		 		pre[i] = pre[i-1];
		 	else
		 		pre[i] = pre[i-1] + 1;
		 }
		}
		
		printf("Case %d:\n", f + 1);
		rep(i,q){
			int s,e;
			scanint(s);
			scanint(e);
			writeInt(pre[e-1] - pre[s-1] + 1);
		}
	}
    return 0;
}