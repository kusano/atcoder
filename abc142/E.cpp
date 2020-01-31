#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;

    vector<int> a(M);
    vector<int> c(M);
    for (int i=0; i<M; i++)
    {
        int b;
        cin>>a[i]>>b;
        for (int j=0; j<b; j++)
        {
            int t;
            cin>>t;
            c[i] |= 1<<(t-1);
        }
    }

    int oo = 999999999;
    vector<int> T(1<<N, oo);
    T[0] = 0;

    for (int i=0; i<M; i++)
    {
        vector<int> P(1<<N, oo);
        P.swap(T);

        for (int b=0; b<1<<N; b++)
        {
            T[b] = min(T[b], P[b]);
            T[b|c[i]] = min(T[b|c[i]], P[b]+a[i]);
        }
    }

    int ans = T[(1<<N)-1];
    cout<<(ans<oo ? ans : -1)<<endl;
}
