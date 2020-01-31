#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    long long A, B;
    cin>>N>>A>>B;
    vector<long long> h(N);
    for (long long &t: h)
        cin>>t;

    auto check = [&](long long c)
    {
        long long x = 0;
        for (long long t: h)
            x += max(0LL, (t-B*c+A-B-1)/(A-B));
        return x<=c;
    };

    long long ans = 0;
    for (long long b=0x80000000LL; b>0; b/=2)
        if (!check(ans+b))
            ans += b;
    cout<<ans+1<<endl;
}
