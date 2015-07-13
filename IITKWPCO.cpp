/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-05 20:37:19
* @Last Modified time: 2015-07-06 12:37:36
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define sci(i) scanf("%d",&i);
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}



int main(){
	int t;
	sci(t);
	while(t--)
	{
		int n;
		sci(n);
		std::vector<int> a(n);
		rep(i,n) sci(a[i]);
		std::sort(a.begin(), a.end());
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				if(a[i] * 2 == a[j])
				{
					++count; 
					a[j] = -1;
					a[i] = -1;
					break;
				}
			}
		}
		printf("%d\n", count);
	}
    return 0;
}