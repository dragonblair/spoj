/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-01 10:54:42
* @Last Modified time: 2015-07-01 11:58:18
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
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
		bool flag = true;
		int a[n];
		rep(i,n) a[i] = 0;
		int temp;
		int sum = 0;
		rep(i,n){
			cin>>temp;
			if(temp >= n){
				flag = false;
				temp = 1;
			}
			a[temp]++;
		}
		if(!flag)
			printf("NO\n");
		else if (!((a[n-1] == 2 && a[0] == 0)||(a[n-1] == 1 && a[0] == 1) || ((a[n-1] == 0 && a[0] == 2))))
			printf("NO\n");
		else
		{
			for (int i = 1; i < (n-2/2); ++i)
			{
				if((a[i] == 2 && a[n-i-1] == 0) || (a[i] == 1 && a[n-i-1] == 1) || (a[i] == 0 && a[n-i-1] == 2))
					continue;
				else
				{
					flag = false;
					printf("NO\n");
					break;
				}
			}
			if(flag){
				if(n % 2 == 1)
				{
					if(a[n/2] == 1)
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
					printf("YES\n");
			}
				
		}
	}
    return 0;
}