/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-30 13:09:03
* @Last Modified time: 2015-06-30 13:27:41
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
		int n;
		cin>>n;
		int in[n],out[n];
		rep(i,n) cin>>in[i]>>out[i];
		int max1 = in[0];
		int maxi = 0;
		int max2 = out[0];
		int maxo = 0;
		for (int i = 1; i < n; ++i)
		{
			if( in[i] > max1 ){
				max1 = in[i];
				maxi = i;
			}
		}
		
		for (int i = 1; i < n; ++i)
		{
			if(i != maxi){
				if(out[i] > max2){
					max2 = out[i];
					maxo = i;
				}
			}
		}
		if(maxo == maxi)
			cout<<1<<endl;
		else if(max2 > max1)
			cout<<-1<<endl;
		else
			cout<<maxi+1<<endl;
	}
    return 0;
}