#include <vector>
using namespace std;

//  Binary Indexed Tree
class BIT
{
    int n;
    vector<int> v;
public:
    BIT(int n_) {
        n = 1;
        while (n < n_)
            n <<= 1;
        v = vector<int>(n);
    }
    //  a[i] += x
    void add(int i, int x) {
        for (; i<n; i|=i+1)
            v[i] += x;
    }
    //  return a[0]+a[1]+c+a[i-1]
    int sum(int i) {
        int s = 0;
        for (i--; i>=0; i=(i&(i+1))-1)
            s += v[i];
        return s;
    }
};

#include <iostream>
#include <utility>
#include <algorithm>

int main()
{
    int N;
    long long K;
    cin>>N>>K;
    vector<long long> a(N);
    for (long long &x: a)
        cin>>x;

    vector<long long> S(N+1);
    for (int i=0; i<N; i++)
        S[i+1] = S[i]+(a[i]-K);

    vector<pair<long long, int>> V;
    for (int i=0; i<N+1; i++)
        V.push_back(make_pair(S[i], i));
    sort(V.begin(), V.end());

    BIT bit(N+1);
    long long ans = 0;
    for (int i=N; i>=0; i--)
    {
        ans += bit.sum(N+1) - bit.sum(V[i].second);
        bit.add(V[i].second, 1);
    }
    cout<<ans<<endl;
}
