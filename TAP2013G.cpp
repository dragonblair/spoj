/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-04 17:03:33
* @Last Modified time: 2015-07-04 19:44:41
* To do : find log(n) search pattern
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define gc getchar
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main(){
	int n;
	scanint(n);
	std::vector<int> a(n);
	std::vector<int> b(n);
	rep(i,n) scanint(a[i]);
	rep(i,n) scanint(b[i]);
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	int count = 0;
	int f = 0;
	for (int i = n-1,j = n-1; i >=0 && j >= f; --i)
	{
		if(b[j] > a[i])
		{
			++count;
			--j;
		}
		else
			++f;
	}
	cout<<count<<endl;
    return 0;
}