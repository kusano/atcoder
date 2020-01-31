#include <iostream>
#include <vector>
using namespace std;

//  a^b % m
long long powmod(long long a, long long b, long long m)
{
    long long r = 1;
    for (; b>0; b>>=1, a=a*a%m)
        if (b&1)
            r = r*a%m;
    return r;
}

int main()
{
    long long n;
    cin>>n;
    long long k;
    cin>>k;

    long long M = 1000000007;
    long long ans = 1;
    for (int i=0; i<k; i++)
        ans = ans*(n+k-i-1)%M*powmod(i+1, M-2, M)%M;
    cout<<ans<<endl;
}
