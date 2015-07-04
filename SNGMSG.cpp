/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-02 13:29:53
* @Last Modified time: 2015-07-02 14:56:11
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

char key[7];
char rkey[7];
char msg[501];
//a-97 z-122
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>key>>msg;

		int lenk = strlen(key);
		for (int i = 0; i < lenk; ++i)
		{
			rkey[i] = key[lenk-i-1];
		}
		
		bool rev = false;
		for (int i = 0,j = 0; i < strlen(msg); ++i)
		{
			int ans = msg[i] - int(key[j]-'0');

			if(ans < 97)
				ans = 122-(97 - ans)+1;
			cout<<(char)ans;
			j++;
			if(j == lenk){
				//key = rkey;
				j = 0;
			}
		}
		cout<<endl;
	}
    return 0;
}