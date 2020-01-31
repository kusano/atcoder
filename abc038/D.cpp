#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;

template<typename T>
class SegmentTree
{
    int n;
    function<T(T,T)> op;
    vector<T> V;

    T q(int l, int r)
    {
        if (l >= r)
            return V[0];
        T a = q((l+1)/2, r/2);
        if (l%2 != 0)
            a = op(a, V[l]);
        if (r%2 != 0)
            a = op(a, V[r-1]);
        return a;
    }

public:
    SegmentTree(int n_, function<T(T,T)> op, T init):
        op(op)
    {
        n = 1;
        while (n < n_)
            n *= 2;
        V = vector<T>(2*n, init);
        for (int i=n-1; i>0; i--)
            V[i] = op(V[i*2], V[i*2+1]);
    }

    T get(int p) const
    {
        return V[p+n];
    }

    void set(int p, T v)
    {
        p += n;
        V[p] = v;
        for (p/=2; p>0; p/=2)
            V[p] = op(V[p*2], V[p*2+1]);
    }

    //  init OP v[l] OP v[l+1] OP ... OP v[r-1]
    T query(int l, int r)
    {
        return q(l+n, r+n);
    }
};

int main()
{
    int N;
    cin>>N;
    vector<int> w(N), h(N);
    for (int i=0; i<N; i++)
        cin>>w[i]>>h[i];

    vector<pair<int, int>> wh(N);
    for (int i=0; i<N; i++)
        wh[i] = make_pair(h[i], -w[i]);
    sort(wh.begin(), wh.end());
    for (int i=0; i<N; i++)
        w[i] = -wh[i].second,
        h[i] = wh[i].first;

    SegmentTree<int> T(100001, [](int a, int b){return max(a, b);}, 0);
    int ans = 0;
    for (int i=0; i<N; i++)
    {
        int t = T.query(0, w[i])+1;
        T.set(w[i], t);
        ans = max(ans, t);
    }
    cout<<ans<<endl;
}
