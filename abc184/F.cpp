#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    long long T;
    cin>>N>>T;
    vector<long long> A(N);
    for (long long &a: A)
        cin>>a;

    vector<long long> S0(1<<(N/2));
    for (int b=0; b<1<<(N/2); b++)
    {
        long long s = 0;
        for (int i=0; i<N/2; i++)
            if (b>>i&1)
                s += A[i];
        S0[b] = s;
    }
    vector<long long> S1(1<<(N-N/2));
    for (int b=0; b<1<<(N-N/2); b++)
    {
        long long s = 0;
        for (int i=0; i<N-N/2; i++)
            if (b>>i&1)
                s += A[N/2+i];
        S1[b] = s;
    }

    sort(S1.begin(), S1.end());
    long long ans = 0;
    for (long long s: S0)
        if (s<=T)
        {
            int p = int(upper_bound(S1.begin(), S1.end(), T-s)-S1.begin());
            ans = max(ans, s+(p==0 ? 0 : S1[p-1]));
        }
    cout<<ans<<endl;
}
