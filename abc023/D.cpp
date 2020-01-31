#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> H(N), S(N);
    for (int i=0; i<N; i++)
        cin>>H[i]>>S[i];

    auto f = [&](long long p)
    {
        vector<long long> T(N);
        for (int i=0; i<N; i++)
        {
            if (H[i]>p)
                return false;
            T[i] = (p-H[i])/S[i];
        }
        sort(T.begin(), T.end());
        for (int i=0; i<N; i++)
            if (T[i]<i)
                return false;
        return true;
    };

    long long ans = 0;
    for (long long i=0x4000000000000000LL; i>0; i/=2)
        if (!f(ans+i))
            ans += i;
    cout<<ans+1<<endl;
}
