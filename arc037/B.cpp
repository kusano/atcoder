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

int main()
{
    int N, M;
    cin>>N>>M;
    vector<int> u(M), v(M);
    for (int i=0; i<M; i++)
        cin>>u[i]>>v[i], u[i]--, v[i]--;

    UnionFind UF(N);
    for (int i=0; i<M; i++)
        UF.unite(u[i], v[i]);
    vector<int> C(N);
    for (int i=0; i<M; i++)
        C[UF.root(u[i])]++;
    int ans = 0;
    for (int i=0; i<N; i++)
        if (UF.root(i)==i && UF.size(i)==C[i]+1)
            ans++;
    cout<<ans<<endl;
}
