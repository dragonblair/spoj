#include <stdio.h>
#include <iostream>
#include <cmath>
#define gc getchar_unlocked

#define pc(x) putchar_unlocked(x);
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
void scanint(long &);
inline void writeInt(int);
long gcd(long a, long b){
	return (b==0)? a : gcd(b, a%b);
}
void reverseArray(int arr[], int start, int end)
{
  int temp;
  while(start < end)
  {
    temp = arr[start];   
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }   
}     
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
inline void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
    }
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
    while(t--){
        long n;
        cin>>n;
        int a[n];
        rep(i,n) scanint(a[i]);
        bool flag = false;
        int index = -1;
        for(int i = n-1; i > 0; --i){
            if(a[i-1]  < a[i] ){
                index = i;
                break;
            }
        }
        if(index != -1){
        for(int j = n-1; j >= index; --j){
            if(a[j] > a[index-1]){
                int temp = a[j];
                a[j] = a[index-1];
                a[index-1] = temp;
                flag = true;
                reverseArray(a, index, n-1);
                break;
            }
        }
        }
        if(flag) {
            rep(i,n) 
                writeInt(a[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}
