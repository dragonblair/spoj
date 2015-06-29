
#include<stdio.h>
#define gc getchar
#define rep(i,n) for(int i = 0; i < n; i++)
#define pc putchar
using namespace std;

void scanint(long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
inline void lprint(int a)
{
 int i=0;
char S[20];
while(a>0)
{
    S[i++]=a%10+'0';
	a=a/10;
}
--i;
while(i>=0){
	pc(S[i--]);
	}
pc('\n');
}
int main(int argc, char const *argv[])
{
	fflush(stdout);
	putchar('a');
	long t;
	scanint(t);
	while(t--){
	long n;
	scanint(n);
	int count = 0;
	while(n / 10 != 0){
		++count;
		long sum = 0;
		long copy = n;
		while(copy != 0){
			long cur = copy % 10;
			sum += cur * cur;
			copy /= 10;
		}
		n = sum;
	}
	if(n == 1)
		lprint(count);
	else if(n == 7)
		lprint(count+5);
	else
		lprint(-1);
	}
	return 0;
}