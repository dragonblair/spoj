#include<iostream>
#include<stdio.h>
#include<cstring>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
int table[] = {0, 0, 0, 0, 1, 1, 1, 1, 6, 2, 4, 8, 1, 3, 9, 7, 6, 4, 6, 4, 
    5, 5, 5, 5, 6, 6, 6, 6, 1, 7, 9, 3, 6, 8, 4, 2, 1, 9, 1, 9};
int calc_digit(int ,long long);
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		char s[1001];
		long long b;
		cin>>s;
		int len = strlen(s);
		//cout<<"length is "<<len<<endl;
		char f_digit = s[len-1] - '0';
		//cout<<f_digit<<" is this " <<endl;
		int a = f_digit;
		cin>>b;
		cout<<calc_digit(a,b)<<endl;
	}
}
int calc_digit(int a, long long b){
	if( a != 0 && b == 0)
		return 1;
	return table[((a % 10) << 2) + ( b & 3)];
}