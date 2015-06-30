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
		int flag = 0;
		int a[n], dummy[n];
		rep(i,n) {
			cin>>a[i];
			dummy[a[i]-1] = i+1;//2,3,4,5,1 => 5,1,2,3,4 => dummy[1] is present at index 5; dummy[2] is present at index 1;  
		}
		rep(i,n){
			if(a[i] != dummy[i]){
				cout<<"not ambiguous"<<endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout<<"ambiguous"<<endl;
			
	}
}while(true);
	return 0;
}