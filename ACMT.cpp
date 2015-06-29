/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-25 15:31:23
* @Last Modified time: 2015-06-25 15:43:12
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



int main(){

	int t;
	cin>>t;
	while(t--)
	{
		int e,n;
		cin>>e>>n;
		int count = 0;
		do
		{
			 if(e > n && e >= 2 && n >= 1)
			 {
				e -= 2;
				n -= 1;
				++count;
			 }
			 else if(n > e && e >= 1 && n >=2)
			 {
			 	e -= 1;
			 	n -= 2;
			 	++count;
			 }
			 else if (n == e && (e >= 2))
			 {
			 	e -= 2;
			 	n -= 1;
			 	++count;
			 }
			 else
			 	break;
		}while(true);
		cout<<count<<endl;
	}
    return 0;
}