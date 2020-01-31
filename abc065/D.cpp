#include <vector>
using namespace std;

class UnionFind
{
public:
    vector<int> parent;
    vector<int> sz;
    
    UnionFind(int n): parent(n), sz(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int root(int x)
    {
        return parent[x]==x ? x : parent[x] = root(parent[x]);
    }

    bool same(int x, int y)
    {
        return root(x)==root(y);
    }

    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (sz[x] < sz[y])
            {
                parent[x] = y;
                sz[y] += sz[x];
            }
            else
            {
                parent[y] = x;
                sz[x] += sz[y];
            }
        }
    }

    int size(int x)
    {
        return sz[root(x)];
    }
};

#include <iostream>
#include <algorithm>
#include <utility>

int main()
{
    int N;
    cin>>N;
    vector<long long> x(N), y(N);
    for (int i=0; i<N; i++)
        cin>>x[i]>>y[i];

    vector<pair<long long, int>> vx(N), vy(N);
    for (int i=0; i<N; i++)
    {
        vx[i] = make_pair(x[i], i);
        vy[i] = make_pair(y[i], i);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    vector<pair<long long, pair<int, int>>> E;
    for (int i=0; i<(int)vx.size()-1; i++)
        E.push_back(make_pair(vx[i+1].first-vx[i].first, make_pair(vx[i].second, vx[i+1].second)));
    for (int i=0; i<(int)vy.size()-1; i++)
        E.push_back(make_pair(vy[i+1].first-vy[i].first, make_pair(vy[i].second, vy[i+1].second)));
    sort(E.begin(), E.end());

    long long ans = 0;
    UnionFind UF(N);
    for (auto e: E)
        if (!UF.same(e.second.first, e.second.second))
        {
            ans += e.first;
            UF.unite(e.second.first, e.second.second);
        }
    cout<<ans<<endl;
}
