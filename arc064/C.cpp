#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

template<class T>
vector<T> dijkstra(vector<vector<int>> E, vector<vector<T>> W, int s, T inf)
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
            if (d+W[p][i] < D[t])
                D[t] = d+W[p][i],
                Q.push(make_pair(D[t], t));
        }
    }
    return D;
}

int main()
{
    double xs, ys, xt, yt;
    cin>>xs>>ys>>xt>>yt;
    int N;
    cin>>N;
    vector<double> x(N), y(N), r(N);
    for (int i=0; i<N; i++)
        cin>>x[i]>>y[i]>>r[i];

    x.push_back(xs);
    y.push_back(ys);
    r.push_back(0.);
    x.push_back(xt);
    y.push_back(yt);
    r.push_back(0.);

    vector<vector<int>> E(N+2);
    vector<vector<double>> W(N+2);
    for (int i=0; i<N+2; i++)
    for (int j=0; j<N+2; j++)
    {
        E[i].push_back(j);
        W[i].push_back(max(0., hypot(x[i]-x[j], y[i]-y[j])-(r[i]+r[j])));
    }

    vector<double> D = dijkstra(E, W, N, 1e10);
    printf("%.10f\n", D[N+1]);
}
