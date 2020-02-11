#include <iostream>
using namespace std;

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
    long long N, M, K;
    cin>>N>>M>>K;

    long long MOD = 1000000007LL;
    long long inv2 = powmod(2, MOD-2, MOD);
    long long px = -1;
    long long py = -1;
    long long ans = 0;
    for (long long y=0; y<N; y++)
        for (long long x=0; x<M; x++)
        {
            ans += y*(y+1)%MOD*inv2%MOD*M%MOD
                + (N-y-1)*(N-y)%MOD*inv2%MOD*M%MOD
                + x*(x+1)%MOD*inv2%MOD*N%MOD
                + (M-x-1)*(M-x)%MOD*inv2%MOD*N%MOD;
            ans %= MOD;
        }
    ans *= inv2;
    ans %= MOD;

    for (long long i=2; i<K; i++)
    {
        ans *= (N*M-i);
        ans %= MOD;
    }
    for (long long i=0; i<K-2; i++)
    {
        ans *= powmod(i+1, MOD-2, MOD);
        ans %= MOD;
    }
    cout<<ans<<endl;
}
