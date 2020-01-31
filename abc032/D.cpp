#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

long long solve1(int N, long long W, vector<long long> v, vector<long long> w)
{
    int n1 = N/2;
    vector<pair<long long, long long>> T1(1<<n1);
    for (int b=0; b<1<<n1; b++)
    {
        long long tv = 0;
        long long tw = 0;
        for (int i=0; i<n1; i++)
            if (b>>i&1)
            {
                tv += v[i];
                tw += w[i];
            }
        T1[b] = make_pair(tw, tv);
    }
    sort(T1.begin(), T1.end());
    for (int i=1; i<1<<n1; i++)
        T1[i].second = max(T1[i].second, T1[i-1].second);

    int n2 = N-n1;
    vector<pair<long long, long long>> T2(1<<n2);
    for (int b=0; b<1<<n2; b++)
    {
        long long tv = 0;
        long long tw = 0;
        for (int i=0; i<n2; i++)
            if (b>>i&1)
            {
                tv += v[n1+i];
                tw += w[n1+i];
            }
        T2[b] = make_pair(tw, tv);
    }
    sort(T2.begin(), T2.end());
    for (int i=1; i<1<<n2; i++)
        T2[i].second = max(T2[i].second, T2[i-1].second);

    long long ans = 0;
    int j = (1<<n2)-1;
    for (int i=0; i<1<<n1; i++)
    {
        if (T1[i].first > W)
            break;
        while (T1[i].first+T2[j].first > W)
            j--;
        ans = max(ans, T1[i].second+T2[j].second);
    }
    return ans;
}

long long solve2(int N, long long W, vector<long long> v, vector<long long> w)
{
    vector<long long> T(1000*N+1, -1);
    T[0] = 0;
    for (int i=0; i<N; i++)
    {
        vector<long long> P(1000*N+1, -1);
        P.swap(T);
        for (int j=0; j<=1000*N; j++)
            if (P[j]>=0)
            {
                T[j] = max(T[j], P[j]);
                T[j+w[i]] = max(T[j+w[i]], P[j]+v[i]);
            }
    }
    long long ans = 0;
    for (int i=0; i<=W; i++)
        ans = max(ans, T[i]);
    return ans;
}

long long solve3(int N, long long W, vector<long long> v, vector<long long> w)
{
    vector<long long> T(1000*N+1, W+1);
    T[0] = 0;
    for (int i=0; i<N; i++)
    {
        vector<long long> P(1000*N+1, W+1);
        P.swap(T);
        for (int j=0; j<=1000*N; j++)
            if (P[j]<W)
            {
                T[j] = min(T[j], P[j]);
                T[j+v[i]] = min(T[j+v[i]], P[j]+w[i]);
            }
    }
    for (int i=1000*N; i>=0; i--)
        if (T[i]<=W)
            return i;
    return 0;
}

int main()
{
    int N;
    long long W;
    cin>>N>>W;
    vector<long long> v(N), w(N);
    for (int i=0; i<N; i++)
        cin>>v[i]>>w[i];

    long long ans;
    if (N<=30)
        ans = solve1(N, W, v, w);
    else if (*max_element(w.begin(), w.end())<=1000)
        ans = solve2(N, W, v, w);
    else
        ans = solve3(N, W, v, w);
    cout<<ans<<endl;
}
