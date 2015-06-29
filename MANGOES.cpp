#include <cstdio> 
main(){int t;scanf("%d",&t);while(t--){long n;scanf("%d",&n);printf("%ld\n",((n/2+1)% n)*((n/2+1)%n)%n);}}