#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    long long x0, a, p;
    cin>>x0>>a>>p;

    long long x = x0;
    vector<int> X;
    for (int i=0; i<N*M; i++)
    {
        X.push_back((int)x);
        x = (x+a)%p;
    }

    vector<pair<int, int>> XP(N*M);
    for (int i=0; i<N*M; i++)
        XP[i] = make_pair(X[i], i);
    sort(XP.begin(), XP.end());
    vector<int> P(N*M);
    for (int i=0; i<N*M; i++)
        P[i] = XP[i].second;

    long long ans = 0;
    for (int y=0; y<N; y++)
    {
        vector<int> T(M);
        for (int x=0; x<M; x++)
        {
            ans += abs(P[y*M+x]/M-y);
            T[x] = P[y*M+x]%M;
        }
        sort(T.begin(), T.end());
        for (int x=0; x<M; x++)
            ans += abs(T[x]-x);
    }
    cout<<ans<<endl;
}
