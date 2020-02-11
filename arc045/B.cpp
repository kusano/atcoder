#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

//  RMQ
template<class T>
class RMQ
{
    int n;
    vector<T> A;

    T q(int l, int r)
    {
        T a = min(A[l], A[r-1]);
        if ((l+1)/2 < r/2)
            a = min(a, q((l+1)/2, r/2));
        return a;
    }

public:
    RMQ(int n_)
    {
        n = 1;
        while (n < n_)
            n *= 2;
        A = vector<T>(2*n, numeric_limits<T>::max());
    }

    void set(int i, T v)
    {
        A[i+n] = v;
        for (int p=(i+n)/2; p>0; p/=2)
            A[p] = min(A[2*p], A[2*p+1]);
    }

    //  [l, r)
    //  if l>=r return invalid
    T query(int l, int r, T invalid)
    {
        if (l<r)
            return q(l+n, r+n);
        else
            return invalid;
    }
};

#include <iostream>

int main()
{
    int N, M;
    cin>>N>>M;
    vector<int> s(M), t(M);
    for (int i=0; i<M; i++)
        cin>>s[i]>>t[i], s[i]--;

    vector<int> T(N+1);
    for (int i=0; i<M; i++)
    {
        T[s[i]]++;
        T[t[i]]--;
    }
    vector<int> S(N);
    S[0] = T[0];
    for (int i=1; i<N; i++)
        S[i] = S[i-1]+T[i];

    RMQ<int> rmq(N);
    for (int i=0; i<N; i++)
        rmq.set(i, S[i]);
    vector<int> ans;
    for (int i=0; i<M; i++)
        if (rmq.query(s[i], t[i], 0)>=2)
            ans.push_back(i);
    cout<<ans.size()<<endl;
    for (int a: ans)
        cout<<a+1<<endl;   
}
