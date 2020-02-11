#include <vector>
#include <functional>

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

#include <iostream>
#include <algorithm>

int main()
{
    int N;
    cin>>N;
    vector<int> P(N);
    for (int &p: P)
        cin>>p, p--;

    vector<int> T(N);
    for (int i=0; i<N; i++)
        T[P[i]] = i;

    SegmentTree<int> L(N, [](int x, int y){return max(x, y);}, -1);
    SegmentTree<int> R(N, [](int x, int y){return min(x, y);}, N);

    long long ans = 0;
    for (int i=N-1; i>=0; i--)
    {
        int p = T[i];
        int l1 = L.query(0, p);
        int l2 = L.query(0, l1);
        int r1 = R.query(p+1, N);
        int r2 = R.query(r1+1, N);
        L.set(p, p);
        R.set(p, p);

        if (0<=l1)
            ans += (long long)(i+1)*(l1-l2)*(r1-p);
        if (r1<N)
            ans += (long long)(i+1)*(p-l1)*(r2-r1);
    }
    cout<<ans<<endl;
}
