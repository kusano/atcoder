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
    int N, M;
    cin>>N>>M;
    vector<int> p(N);
    for (int &t: p)
        cin>>t, t--;
    vector<int> x(M), y(M);
    for (int i=0; i<M; i++)
        cin>>x[i]>>y[i], x[i]--, y[i]--;

    UnionFind UF(N);
    for (int i=0; i<M; i++)
        UF.unite(x[i], y[i]);

    vector<set<int>> V(N);
    for (int i=0; i<N; i++)
        V[UF.root(i)].insert(i);
    int ans = 0;
    for (int i=0; i<N; i++)
        for (int x: V[i])
            if (V[i].count(p[x]))
                ans++;
    cout<<ans<<endl;
}
