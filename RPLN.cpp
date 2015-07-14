/* 
* @Author: Krishna Kalubandi
* @Date:   2015-07-14 18:54:12
* @Last Modified time: 2015-07-14 19:44:38
* @Solution to Problem : http://www.spoj.com/problems/UJ01/RPLN.cpp
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <climits>
#define ull usigned long long
#define ll long long
#define sci(i) scanf("%d",&i)
#define scl(i) scanf("%ld",&i)
#define scll(i) scanf("%lld",&i)
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)
#define gc getchar
using namespace std;

int max (int a, int b) { return a > b ? a : b;}
int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int query(int *ss,int s,int e,int l,int r,int h)
{
	if(l > e || r < s)
		return INT_MAX;
	else if(l >= s && r <= e)
		return ss[h];
	else
	{
		int mid = (l+r)/2;
		return min(query(ss,s,e,l,mid,2*h+1),query(ss,s,e,mid+1,r,2*h+2));
	}

}
int buildTree(int arr[],int l,int r,int h,int *ss)
{
	if(l == r)
	{
		ss[h] = arr[l];
		return arr[l];
	}
	int mid = (l+r)/2;

	ss[h] = min(buildTree(arr,l,mid,2*h+1,ss),buildTree(arr,mid+1,r,2*h+2,ss));
	
	return ss[h];
}

int main(){
	int t;
	sci(t);
	for(int i = 1; i <= t; ++i)
	{
		printf("Scenario #%d:\n",i);
		int n,q;
		scanint(n);scanint(q);
		int a[n];
		int size = ceil(log2(n));
		size = 2 * pow(2,size) - 1;
		int *ss = new int[size];
		rep(i,n) scanint(a[i]);
		buildTree(a,0,n-1,0,ss);
		while(q--)
		{
			int a,b;
			scanint(a);scanint(b);
			printf("%d\n",query(ss,a-1,b-1,0,n-1,0));
		}
	}
    return 0;
}