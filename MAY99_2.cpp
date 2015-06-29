/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-18 18:05:29
* @Last Modified time: 2015-06-18 18:56:52
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

unsigned long long MAX =  1000000000000000000ULL;
long long sum[27];
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;


int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}


void precomp()
{
	int count = 0;
	long long tsum = 0;
	long long pwr = 1;
	while(tsum <= MAX)
	{
		tsum += pwr;
		sum[count] = tsum;
		pwr *= 5;
		++count;
	}
	
}
const char words[] = {'m','a','n','k','u'};
int main(){
	precomp();

	int t;
	cin>>t;
	
	while(t--){
		char ans[27];
		long long int n;
		cin>>n;
		int i;
		for(i = 0; n >= sum[i]; i++)
		{
			ans[i] = 'm';
		}
		ans[i] = '\0';
		long long offset = n - sum[i-1];
		
		int index = i - 1;

		while(offset != 0)
		{
			ans[index] = words[offset % 5];
			offset /= 5;
			index--;
		}
		cout<<ans<<endl;
	}
    return 0;
}