#include<iostream>
using namespace std;
char s[201];
int dp[201][201];
int size;
int calcRocks(int i, int j);
int max(int a,int b);
int calcSourSweet(int,int);
int main(){
	
	int t;
	cin>>t;
	while(t--){
		cin>>size;
		cin>>s;
		for(int i = 0; i < 201; i++)
		for(int j = 0; j < 201; j++)
		dp[i][j] = -1;
		cout<<calcRocks(0,size-1)<<endl;
	}
}
int calcRocks(int i, int j){
	
	if(dp[i][j] != -1)
		return dp[i][j];

	if(i == j)
	{
		dp[i][i] = (s[i] == '0' ? 0 : 1);
		//cout<<"In here bro adding i: " <<i <<" and j: "<<endl;
		return dp[i][i]; 
	}
		
	
	if(calcSourSweet(i,j) > 0){
		dp[i][j] = j-i+1;
		return dp[i][j];
	}
		
	else{
		int ret = 0;
		for(int k = i+1; k <= j; k++){
			ret = max(ret, calcRocks(i,k-1) + calcRocks(k,j));
		}
		//cout<<"In here bro adding i: " <<i <<" and j: "<<j<< " ret :" <<ret<<endl;
		dp[i][j] = ret;
		return dp[i][j];
	}
	return dp[0][size-1];
}
int max(int a, int b){
	return a>b?a:b;
}
int calcSourSweet(int i, int j){
	int count = 0;
	for(int k = i; k <= j; k++){
		if(s[k] == '0')
			count--;
		else
			count++;
	}
	return count;
}

