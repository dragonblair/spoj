/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-24 16:04:37
* @Last Modified time: 2015-06-24 18:19:15
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

string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int odd_days[4] = {0,1,3,5};
int month_odd_days[12] = {3,0,3,2,3,2,3,3,2,3,2,3};
string find_day(int d,int m, int y)
{
	int copy = y;
	y -= 2001;

	y %= 400;

	int cur_odd_days = 0;

	if(y / 100 == 1)
		cur_odd_days += 5;
	else if(y / 100 == 2)
		cur_odd_days += 3;
	else if(y / 100 == 3)
		cur_odd_days += 1;

	y %= 100;

	int leap_years = y/4;
	cur_odd_days += (leap_years) * 2 + ( y - leap_years);
	m--;
	rep(i,m)
	{
		cur_odd_days += month_odd_days[i];
		if(i == 1 && (copy % 4 == 0)){
			if(copy % 100 == 0)
			{
				if(copy % 400 == 0){
					//cout<<"chekku"<<endl;
					cur_odd_days += 1;
					}
			}
			else
				cur_odd_days += 1;
		}
	}
		

	cur_odd_days += (d % 7);
	cur_odd_days %= 7;
	return days[cur_odd_days];
} 
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int d,m,y;
		cin>>d>>m>>y;
		cout<<find_day(d,m,y)<<endl;
	}
    return 0;

}