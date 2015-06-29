#include <iostream>
#include <cmath>
using namespace std;
const int seive = 10000000;
int primes[seive+1];
int calcPrimes(){
		primes[1] = 1;
		for(long long i = 2; i <= seive; i++){
			if(!primes[i]){
				primes[i] = i;
				for(long long j = i ; j * i <= seive; j++)
				{
					if(!primes[j*i]) primes[j*i] = i;
				}
			}
		}
}
int main()
{
	calcPrimes();
	int n;
	while(scanf("%d",&n) != EOF ) {
		printf("1");
		if(n == 1){
			printf("\n");
			continue;
			}
		while(n != primes[n] && n != 0)
		{
			printf(" x %d",primes[n]);
			n /= primes[n];
		}
			
		if(n != 1)
			printf(" x %d",n);
		printf("\n");
	}
	system("pause");
}