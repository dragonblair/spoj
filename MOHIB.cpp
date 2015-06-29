/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-25 12:09:39
* @Last Modified time: 2015-06-25 12:11:19
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
	while(t--){
		int avg,x;
		cin>>x>>avg;

		int terms = avg - x;

		int sum = terms * (avg + 1);

		int ans = sum - ((terms-1)*(terms)/2);

		cout<<ans<<endl;
	}

    return 0;
}