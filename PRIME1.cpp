/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-10 10:49:00
* @Last Modified time: 2015-07-10 12:43:34
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#define si(i) scanf("%d",&i)
#define pi(i) printf("%d\n", i);
#include <vector>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)
 
int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){
	//calcPrimes();
	int t;
	si(t);
	while(t--){
		int a,b;
		si(a);
		si(b);
		if(a == 1) ++a;
		
		if(b < 2)
		{
			pi(0);
		}
		else
		{
			if(a <= 2 && 2<=b) pi(2);
			if(a%2 == 0) a++;
			for (int i = a; (i <= b); i += 2)
			{
				bool prime = true;
				for (int k = 3; k * k <= i; k += 2)
				{
					if(i % k == 0)
					{
						prime = false;
						break;
					}
				}
				if(prime) pi(i);
			}
		}
	}
    return 0;
}