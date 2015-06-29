#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a = 0;
		long long b = 1;
		long long c = a+b;
		while(n--){

			a = b;
			b = c;
			c = a + b;
			
		}
		cout <<  c  <<endl;
	}
	return 0;
}