/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-13 11:34:39
* @Last Modified time: 2015-07-13 11:46:42
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define sc(i) scanf("%d",&i)
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){
	int t;
	sc(t);
	while(t--)
	{
		int h,a;
		sc(h);
		sc(a);
		int x = 0;
		int s = 0;
		while(h > 0 && a >0)
		{
			if(s)
			{
				if(h>20 && a<=10)
				{
					h -= 20;
					a += 5;
				}
				else
				{
					h -= 5;
					a -= 10;
				}
			}
			else
			{
				h += 3;
				a += 2;
			}
			s = !s;
			if(h > 0 && a >0)
				++x;	
		}
		printf("%d\n",x);
	}

    return 0;
}