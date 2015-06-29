//factorial
#include<iostream>
#include<map>
using namespace std;
long long ncr(int ,int);
int main(){
	int tt;
	int n,r;
	cin>>tt;
	while(tt--){
		cin>>n>>r;
		cout << ncr(n-1,r-1) << endl;
	}
	
}
long long ncr(int n , int r){
	r = r > n-r ? n-r : r;
	long long ans = 1;
	int j = 1;
	for(;j <= r; j++,n--){
		if(n % j == 0)
			ans *= n/j;
		else if(ans % j == 0)
			ans = ans/j * n;
		else
			ans = (ans*n)/j;
	}
	return ans; 
}