/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-17 15:40:20
* @Last Modified time: 2015-06-17 16:20:29
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}


char s[21];
int main(){

	do{
		cin >> s;
		if(s[0] == '*')
			break;
		else
		{
			long long ans = 1;
			for(int i = 0; s[i] != '\0'; ++i)
			{
				if(s[i] == 'Y')
				{
					ans = (ans * (i+1)) / gcd(ans, i + 1);
				}
			}
			bool flag = true;
			for (int i = 0; s[i] != '\0'; ++i)
			{
				if(s[i] == 'N')
				{
					if(ans % (i + 1) == 0){
						flag = false;
						cout<<"-1"<<endl;
						break;
					}
				}
			}
			if(flag)
				cout<<ans<<endl;
		}

	}while(true);
    return 0;
}