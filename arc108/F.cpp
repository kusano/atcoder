#include <vector>
#include <queue>
#include <functional>
#include <utility>
 
using namespace std;
 
//  E[i]: vertexes which can be reased from i
//  W[i]: their weight
template<class T>
vector<T> dijkstra(vector<vector<int>> E, int s, T inf)
{
    int n = (int)E.size();
 
    vector<T> D(n, inf);
    typedef pair<T,int> P;
    priority_queue<P,vector<P>,greater<P>> Q;
 
    D[s] = T();
    Q.push(make_pair(D[s], s));
 
    while (!Q.empty())
    {
        T d = Q.top().first;
        int p = Q.top().second;
        Q.pop();
        if (d > D[p])
            continue;
        for (int i=0; i<(int)E[p].size(); i++)
        {
            int t = E[p][i];
            if (d+1 < D[t])
                D[t] = d+1,
                Q.push(make_pair(D[t], t));
        }
    }
    return D;
}
 
#include <iostream>
 
int main()
{
    int N;
    cin>>N;
    vector<vector<int>> E(N);
    for (int i=0; i<N-1; i++)
    {
        int a, b;
        cin>>a>>b;
        E[a-1].push_back(b-1);
        E[b-1].push_back(a-1);
    }
 
    vector<int> D = dijkstra(E, 0, N);
    int x = 0;
    for (int i=1; i<N; i++)
        if (D[i]>D[x])
            x = i;
    vector<int> Dx = dijkstra(E, x, N);
    int y = 0;
    for (int i=1; i<N; i++)
        if (Dx[i]>Dx[y])
            y = i;
    vector<int> Dy = dijkstra(E, y, N);
 
    vector<int> Dmin(N), Dmax(N);
    for (int i=0; i<N; i++)
        if (i!=x && i!=y)
        {
            Dmin[min(Dx[i], Dy[i])]++;
            Dmax[max(Dx[i], Dy[i])]++;
        }
    vector<int> Smin(N);
    Smin[N-1] = Dmin[N-1];
    for (int i=N-2; i>=0; i--)
        Smin[i] = Smin[i+1]+Dmin[i];
    vector<int> Smax(N);
    Smax[0] = Dmax[0];
    for (int i=1; i<N; i++)
        Smax[i] = Smax[i-1]+Dmax[i];
 
    long long M = 1000000007;
    vector<long long> P2(N+1);
    P2[0] = 1;
    for (int i=1; i<=N; i++)
        P2[i] = P2[i-1]*2%M;
 
    vector<long long> S(N);
    for (int i=0; i<N-1; i++)
        if (Smin[i+1]==0)
            S[i] = P2[Smax[i]];
 
    int d = 0;
    for (int t: Dx)
        d = max(d, t);
    long long ans = d*P2[N-1];
    for (int i=1; i<N-1; i++)
        if (Smin[i+1]==0)
            (ans += 2*i*(S[i]-S[i-1]+M)) %= M;
    cout<<ans<<endl;
}
