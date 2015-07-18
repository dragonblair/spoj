/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-18 18:05:29
* @Last Modified time: 2015-07-15 09:57:02
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

unsigned long long MAX =  10e15;
long long *sum;
int size;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;


int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}


void precomp()
{
	size = ceil(log2(MAX));
	sum = new long long[size];
	int count = 0;
	long long tsum = 0;
	long long pwr = 1;
	while(tsum <= MAX)
	{
		tsum += pwr;
		sum[count] = tsum;
		pwr *= 2;
		++count;
	}
	
}
const char words[] = {'5','6'};
int main(){
	precomp();

	int t;
	cin>>t;
	
	while(t--){
		char ans[size];
		long long int n;
		cin>>n;
		int i;
		for(i = 0; n >= sum[i]; i++)
		{
			ans[i] = '5';
		}
		ans[i] = '\0';
		long long offset = n - sum[i-1];
		
		int index = i - 1;

		while(offset != 0)
		{
			ans[index] = words[offset % 2];
			offset /= 2;
			index--;
		}
		cout<<ans<<endl;
	}
    return 0;
}