#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    vector<int> u(M), v(M), l(M);
    for (int i=0; i<M; i++)
    {
        cin>>u[i]>>v[i]>>l[i];
        u[i]--;
        v[i]--;
    }

    int oo = 1000000000;
    vector<vector<int>> T(N, vector<int>(N, oo));
    for (int i=0; i<M; i++)
        if (u[i]!=0)
        {
            T[u[i]][v[i]] = l[i];
            T[v[i]][u[i]] = l[i];
        }
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        for (int k=0; k<N; k++)
            T[j][k] = min(T[j][k], T[j][i]+T[i][k]);
    
    int ans = oo;
    for (int i=0; i<M; i++)
    if (u[i]==0)
        for (int j=0; j<i; j++)
        if (u[j]==0)
            ans = min(ans, l[i]+l[j]+T[v[i]][v[j]]);
    cout<<(ans<oo ? ans : -1)<<endl;
}
