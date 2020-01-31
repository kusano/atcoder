#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    vector<int> a(M), b(M), c(M);
    for (int i=0; i<M; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;
        b[i]--;
    }

    int oo = 99999999;
    vector<vector<int>> D(N, vector<int>(N, oo));
    for (int i=0; i<M; i++)
    {
        D[a[i]][b[i]] = c[i];
        D[b[i]][a[i]] = c[i];
    }
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            for (int k=0; k<N; k++)
                D[j][k] = min(D[j][k], D[j][i]+D[i][k]);
    int ans = 0;
    for (int i=0; i<M; i++)
        if (D[a[i]][b[i]] != c[i])
            ans++;
    cout<<ans<<endl;
}
