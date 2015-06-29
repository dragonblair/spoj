#include <iostream>
using namespace std;

int calcSum(long long n){

	 int sum = 0;
	 while(n != 0)
	 {
	 	sum += (n % 10);
	 	n /= 10;
	 }
	 return sum;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		do{
			if(n % calcSum(n) == 0)
			{
				cout<<n<<endl;
				break;
			}
			else
				++n;
		}while(true);
	}
	return 0;
}