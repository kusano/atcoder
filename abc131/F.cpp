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
#include <set>

int main()
{
    int N;
    cin>>N;
    vector<int> x(N), y(N);
    for (int i=0; i<N; i++)
    {
        cin>>x[i]>>y[i];
        x[i]--;
        y[i]--;
    }

    vector<vector<int>> vx(100000), vy(100000);
    for (int i=0; i<N; i++)
        vx[x[i]].push_back(i),
        vy[y[i]].push_back(i);

    UnionFind U(N);
    for (int i=0; i<100000; i++)
    {
        for (int v: vx[i])
            U.unite(vx[i][0], v);
        for (int v: vy[i])
            U.unite(vy[i][0], v);
    }

    vector<vector<int>> G(N);
    for (int i=0; i<N; i++)
        G[U.root(i)].push_back(i);

    long long ans = 0;
    for (int i=0; i<N; i++)
    {
        set<int> sx, sy;
        for (int g: G[i])
            sx.insert(x[g]),
            sy.insert(y[g]);
        ans += sx.size()*sy.size() - G[i].size();
    }
    cout<<ans<<endl;
}
