#include<iostream>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
int main(int argc, char const *argv[])
{
	do{
	int n;
	cin>>n;
	if(n == 0)
		return 0;
	else{
		long ans = (n * (n + 1) * (2 * n + 1)) / 6;
		cout<<ans<<endl;
	}
}while(true);
}