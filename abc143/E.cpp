#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    long long L;
    cin>>N>>M>>L;

    long long oo = 1'000'000'000'000'000;
    vector<vector<long long>> D1(N, vector<long long>(N, oo));
    for (int i=0; i<M; i++)
    {
        int A, B;
        long long C;
        cin>>A>>B>>C;
        D1[A-1][B-1] = D1[B-1][A-1] = C;
    }

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            for (int k=0; k<N; k++)
                D1[j][k] = min(D1[j][k], D1[j][i]+D1[i][k]);

    vector<vector<long long>> D2(N, vector<long long>(N, oo));
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (D1[i][j]<=L)
                D2[i][j] = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            for (int k=0; k<N; k++)
                D2[j][k] = min(D2[j][k], D2[j][i]+D2[i][k]+1);

    int Q;
    cin>>Q;
    for (int i=0; i<Q; i++)
    {
        int s, t;
        cin>>s>>t;
        cout<<(D2[s-1][t-1]<oo ? D2[s-1][t-1] : -1)<<endl;
    }
}
