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
    int N, M;
    cin>>N>>M;
    vector<long long> c(N);
    for (long long &t: c)
        cin>>t;
    vector<int> a(M+N), b(M+N);
    vector<long long> r(M+N);
    for (int i=0; i<M; i++)
    {
        cin>>a[i]>>b[i]>>r[i];
        a[i]--;
        b[i]--;
    }

    for (int i=0; i<N; i++)
    {
        a[M+i] = i;
        b[M+i] = N;
        r[M+i] = c[i];
    }

    vector<pair<long long, int>> P(M+N);
    for (int i=0; i<M+N; i++)
        P[i] = make_pair(r[i], i);
    sort(P.begin(), P.end());

    UnionFind UF(M+N);
    long long ans = 0;
    for (int i=0; i<M+N; i++)
    {
        int e = P[i].second;
        if (!UF.same(a[e], b[e]))
        {
            UF.unite(a[e], b[e]);
            ans += r[e];
        }
    }
    cout<<ans<<endl;
}
