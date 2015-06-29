#include<iostream>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
int main(int argc, char const *argv[])
{
	do{
	int n;
	cin>>n;
	if(n == -1)
		return 0;
	else{

			int a[n];
			long long sum = 0;
			rep(i,n){
				cin >> a[i];
				sum += a[i];
			}
			float avg = (float)sum / n;
			int x = (int)avg;
			if(avg - x > 0){
				cout<<"-1"<<endl;
				}
			else{
				int moves = 0;
				rep(i,n){
					if(avg - a[i] > 0)
						moves += (avg - a[i]);
				}
				cout<<moves<<endl;
			}

		}
	}while(true);
	return 0;
}
