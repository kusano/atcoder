#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin>>N>>K;
    vector<long long> a(N);
    for (long long &x: a)
        cin>>x;
    vector<long long> b(N);
    for (long long &x: b)
        cin>>x;

    sort(b.begin(), b.end());

    auto f = [&](long long X)
    {
        long long c = 0;
        for (long long t: a)
            c += upper_bound(b.begin(), b.end(), X/t)-b.begin();
        return c;
    };

    long long ans = 0;
    for (long long b=1LL<<62; b>0; b/=2)
        if (f(ans+b)<K)
            ans += b;
    ans++;
    cout<<ans<<endl;
}
