/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-14 11:05:58
* @Last Modified time: 2015-07-14 11:37:00
* @Solution to Problem : http://www.spoj.com/problems/UJ01/PTIME.cpp
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#define ull unsigned long long
#define ll long long
#define sci(i) scanf("%d",&i)
#define scl(i) scanf("%ld",&i)
#define scll(i) scanf("%lld",&i)
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}

const int seive = 10007;
int primes[seive+1];
int calcPrimes(){
		primes[1] = 1;
		for(long long i = 2; i <= seive; i++){
			if(!primes[i]){
				primes[i] = i;
				for(long long j = i ; j * i <= seive; j++)
				{
					if(!primes[j*i]) primes[j*i] = i;
				}
			}
		}
}

int main(){
	calcPrimes();
	int t;
	sci(t);
	std::map<int, int> map;
	for (int k = 2; k <= t; ++k)
	{
		int j = k;
		while(j != primes[j] && j != 0)
		{
			map[primes[j]]++;
			j /= primes[j];
		}
		if(j != 1)
			map[j]++;
	}
	int j = 0;
	for (std::map<int,int>::iterator i = map.begin(); i != map.end() && (j < map.size()-1); ++i,++j)
	{
		printf("%d^%d * ",i->first,i->second);
	}
	printf("%d^%d",map.rbegin()->first,map.rbegin()->second);
	//system("pause");
    return 0;
}