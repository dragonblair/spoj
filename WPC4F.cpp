/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-27 22:13:35
* @Last Modified time: 2015-06-30 11:10:27
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}
int a[21][3];
int main(){

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		rep(i,n)
			rep(j,3)
				cin>>a[i][j];

		for (int i = 1; i < n; ++i)
		{
			a[i][0] += min(a[i-1][1],a[i-1][2]);
			a[i][1] += min(a[i-1][0],a[i-1][2]);
			a[i][2] += min(a[i-1][1],a[i-1][0]);
		}
		cout<<min(min(a[n-1][0],a[n-1][1]),a[n-1][2])<<endl;
	}
    return 0;
}