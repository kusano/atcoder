#include <iostream>
#include <vector>
#include <algorithm>
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
    int N;
    cin>>N;
    vector<long long> C(N);
    for (long long &c: C)
        cin>>c;

    sort(C.begin(), C.end());
    long long M = 1000000007;
    long long ans = 0;
    for (int i=N-1; i>=0; i--)
    {
        ans += C[i]*powmod(2, N-2+(M-1), M)%M*(2+N-i-1)%M;
        ans %= M;
    }
    ans *= powmod(2, N, M);
    ans %= M;
    cout<<ans<<endl;
}
