/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-27 22:13:35
* @Last Modified time: 2015-06-28 09:34:25
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
int a[101][101];
int main(){
		int t;
		cin>>t;
		while(t--){
		int n,m;
		cin>>n>>m;
		rep(i,n)
			rep(j,m)
				cin>>a[i][j];

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int x = j-1;
				int y = j+1;
				if( x < 0 ) x = 0;
				if(y == m)  y = m-1;
				a[i][j] += max(max(a[i-1][x],a[i-1][y]), a[i-1][j]);
			}
		}
		int ans = -1;
		for (int i = 0; i < m; ++i)
		{
			if(a[n-1][i] > ans)
				ans = a[n-1][i];
		}
		cout<<ans<<endl;
	}
    return 0;
}