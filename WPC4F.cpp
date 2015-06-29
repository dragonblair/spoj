/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-27 22:13:35
* @Last Modified time: 2015-06-27 23:53:28
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

int findmin(int a[][3] , int i, int j)
{
	if (i == 0)
	{
		return a[i][j];
	}
	
	int min = 1000000;
	for (int k = j; k < 3; ++k)
	{
		rep(l,3)
		{
			if( l != j)
			{
				int ans = a[i][k] + findmin(a,i-1,l);
				cout<<ans<<endl;
				if (ans < min)
				{
					min = ans;
				}
			}

		}
	}
	return min;
}

int main(){

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n][3];
		rep(i,n)
			rep(j,3)
				cin>>a[i][j];
		cout<<findmin(a,n-1,0)<<endl;	
	}
	system("pause");
    return 0;
}