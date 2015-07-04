/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-03 12:05:16
* @Last Modified time: 2015-07-04 11:50:44
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
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
		int n;
		cin>>n;
		int sum = 0,count = 0;
		while(sum < n)
		{
			sum += pow(3,count);
			count++;
		}
		//cout<<count<<endl;		
		char *ans = new char[count];
		rep(i,count) ans[i] = '+';
		//cout<<ans<<endl;
		for (int i = count-1; i >= 0; --i)
		{
			if(sum - 2*pow(3,i) >= n)
			{
				//cout<<"- "<<sum<<" pow "<<pow(3,i)<<endl;
				sum -= 2*pow(3,i);
				ans[i] = '-';
			}
			else if(sum - pow(3,i) >= n)
			{
				//cout<<"0 "<<sum<<" pow "<<pow(3,i)<<endl;
				sum -= pow(3,i);
				ans[i] = '0';
			}
		}
		for (int i = count-1; i >= 0; --i)
		 {
		 	cout<<ans[i];
		 } 
		cout<<endl;
	}
    return 0;
}