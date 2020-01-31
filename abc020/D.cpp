#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long N, K;
    cin>>N>>K;

    long long M = 1000000007;

    vector<long long> F;
    for (long long f=1; f*f<=K; f++)
    {
        if (K%f==0)
        {
            F.push_back(f);
            if (f*f!=K)
                F.push_back(K/f);
        }
    }
    sort(F.begin(), F.end());

    long long n = F.size();
    vector<long long> T(n, -1);
    long long ans = 0;
    for (int i=0; i<n; i++)
    {
        long long x = 0;
        for (int j=0; j<i; j++)
            if (F[i]%F[j]==0)
                x += F[i]/F[j]*T[j]%M;
        T[i] = (1-x+M)%M;

        long long t = N/F[i];
        ans += t*(t+1)/2%M*T[i]%M;
        ans = (ans%M+M)%M;
    }
    ans = ans*K%M;
    cout<<ans<<endl;
}
