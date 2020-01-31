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
#include <map>
#include <utility>

int main()
{
    int N, K, L;
    cin>>N>>K>>L;
    vector<int> p(K), q(K);
    for (int i=0; i<K; i++)
    {
        cin>>p[i]>>q[i];
        p[i]--;
        q[i]--;
    }
    vector<int> r(L), s(L);
    for (int i=0; i<L; i++)
    {
        cin>>r[i]>>s[i];
        r[i]--;
        s[i]--;
    }

    UnionFind UF1(N);
    for (int i=0; i<K; i++)
        UF1.unite(p[i], q[i]);
    UnionFind UF2(N);
    for (int i=0; i<L; i++)
        UF2.unite(r[i], s[i]);

    map<pair<int, int>, int> M;
    for (int i=0; i<N; i++)
        M[make_pair(UF1.root(i), UF2.root(i))]++;
    for (int i=0; i<N; i++)
        cout<<(i==0?"":" ")<<M[make_pair(UF1.root(i), UF2.root(i))];
    cout<<endl;
}
