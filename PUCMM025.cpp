/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-21 15:08:09
* @Last Modified time: 2015-06-21 15:53:12
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

char str[250];
int divby[] = { 1, 3, 2, 6, 4, 5 };
bool divByFour(){

	int len = strlen(str);
	if(len == 1){
		return ((str[0] - '0') % 4 == 0);
	}
	int digits = (str[len-1] - '0') + (( str[len-2] - '0') * 10);

	if(digits % 4 == 0)
		return true;
	return false;
}
bool divByEight(){

	int len = strlen(str);

	if(len == 1){
		return ((str[0] - '0') % 8 == 0);
	}
	else if(len == 2){
		int digits = (str[len-1] - '0') + (( str[len-2] - '0') * 10);

		return(digits%8 == 0);
	}
	else
	{
		int digits = (str[len-1] - '0') + (( str[len-2] - '0') * 10) + (( str[len-3] - '0') * 100);

			return (digits%8==0);
	}

}
bool divBySeven(){

	long long sum = 0;
	int len = strlen(str);
	for(int i = len-1; i >= 0; --i )
		sum += divby[(len-1-i)%6] * (str[i] - '0');
	if(sum % 7 == 0)
		return true;
	return false;
}
int divByNineAndThree(){

 int len = strlen(str); 
 long long sum = 0;
 for(int i = 0; i < len; ++i )
 	sum += (str[i] - '0');

 if(sum % 9 == 0 && sum % 3 == 0)
 	return 2;
 else if(sum % 3 == 0)
 	return 1;
 else
 	return 0;
}

int main(){

	while(scanf("%s",str)!=EOF)
	{
		int len = strlen(str);
		bool occured[9] = { false, false,false,false,false,false, false,false,false};
		bool divcheck[9]= { false, false,false,false,false,false, false,false,false};
		int tcount = 0;
		for (int i = 0; i < len; ++i)
		{
			int num = (str[i] - '0');
			if(num == 0)
				continue;
			if(!occured[num-1] && !divcheck[num-1])
			{
				occured[num-1] = true;
				if(num == 2)
				{
					if(((int)(str[len-1] - '0') % 2) == 0)
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 3)
				{
					int nt = divByNineAndThree();
					if (nt >= 1)
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 4)
				{
					if (divByFour())
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 5)
				{
					
					if (str[strlen(str) - 1] == '0' || str[strlen(str) - 1] == '5')
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 6)
				{
					if((((int)(str[len-1] - '0') % 2) == 0) && (divByNineAndThree() >= 1))
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 7)
				{
					if (divBySeven())
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 8)
				{
					if (divByEight())
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 9)
				{
					if (divByNineAndThree() == 2)
					{
						divcheck[num-1] = true;
						tcount++;
					}
				}
				else if(num == 1)
					{
						divcheck[0] = true;
						tcount++;
					}
			}
			else if(occured[num-1] && divcheck[num-1])
				tcount++;
		}
		cout<<tcount<<endl;
	}
    return 0;
}