/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-04 14:28:18
* @Last Modified time: 2015-07-04 14:29:22
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
		if(n & 1)
			printf("Sorry Shaktiman\n");
		else
			printf("Thankyou Shaktiman\n");
	}
    return 0;
}