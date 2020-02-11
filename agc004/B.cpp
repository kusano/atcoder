#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    long long x;
    cin>>N>>x;
    vector<long long> a(N);
    for (long long &t: a)
        cin>>t;

    vector<long long> T = a;
    long long s = 0;
    for (long long t: T)
        s += t;
    long long ans = s;
    for (int i=1; i<N; i++)
    {
        vector<long long> P(N, 1000000000000000LL);
        P.swap(T);
        for (int j=0; j<N; j++)
            T[j] = min(P[j], P[(j+N-1)%N]);
        s = 0;
        for (long long t: T)
            s += t;
        ans = min(ans, s+i*x);
    }
    cout<<ans<<endl;
}
