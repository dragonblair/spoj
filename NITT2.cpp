/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-21 13:42:05
* @Last Modified time: 2015-06-21 15:04:29
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


int divby[] = { 1, 3, 2, 6, 4, 5 };

char input[50010];

bool divByFour(){

	int len = strlen(input);

	int digits = (input[len-1] - '0') + (( input[len-2] - '0') * 10);

	if(digits % 4 == 0)
		return true;
	return false;
}
bool divBySeven(){

	long long sum = 0;
	int len = strlen(input);
	for(int i = len-1; i >= 0; --i )
		sum += divby[(len-1-i)%6] * (input[i] - '0');
	if(sum % 7 == 0)
		return true;
	return false;
}
int divByNineAndThree(){

 int len = strlen(input); 
 long long sum = 0;
 for(int i = 0; i < len; ++i )
 	sum += (input[i] - '0');

 if(sum % 9 == 0 && sum % 3 == 0)
 	return 2;
 else if(sum % 3 == 0)
 	return 1;
 else
 	return 0;
}

bool divByTwentyFive(){

	int len = strlen(input); 

	if((input[len-1] == '0' && input[len-2] == '0') || (input[len-1] == '5' && input[len-2] == '2')
	 || (input[len-1] == '5' && input[len-2] == '7') || (input[len-1] == '0' && input[len-2] == '5'))
		return true;
	return false;


}
int main(){

	int n;
	cin>>n;
	while(n--)
	{

		scanf("%s",input);

		bool four = divByFour();
		bool seven = divBySeven();
		int nt = divByNineAndThree();
		bool tf = divByTwentyFive();

		// 252 - 4,7,9
		// 525 - 3,7,25

		if( four && seven && (nt==2))
			cout<<"Yes ";
		else
			cout<<"No ";
		if((nt >= 1) && seven && tf)
			cout<<"Yes ";
		else
			cout<<"No ";
		cout<<endl;
	}
    return 0;
}