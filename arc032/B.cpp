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
    UnionFind UF(N);
    for (int i=0; i<M; i++)
    {
        int a, b;
        cin>>a>>b;
        UF.unite(a-1, b-1);
    }
    set<int> S;
    for (int i=0; i<N; i++)
        S.insert(UF.root(i));
    cout<<S.size()-1<<endl;
}
