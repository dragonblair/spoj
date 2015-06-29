#include<stdio.h>
#define gc getchar
#define rep(i,n) for(int i = 0; i < n; i++)
#define pc(x) putchar(x);
using namespace std;

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
        pc(' ');
    }
int main(int argc, char const *argv[])
{
    int n,k;
    scanint(n);
    int arr[n];
    rep(i,n)
        scanint(arr[i]);
    scanint(k);
    int max = -1;
    
    for (int i = 0; i <= (n-k); ++i){
        int count = 0;
        for (int j = i;count < k; ++j,++count)
        {
            if(arr[j] > max)
                max = arr[j];
        }
        writeInt(max);
        max = -1;
    }
    return 0;
}