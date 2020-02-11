#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> A(N);
    for (int &a: A)
        cin>>a, a--;

    //  C1[a] = num(a)
    vector<int> C1(N);
    for (int a: A)
        C1[a]++;
    //  C2[c] = num(c)
    vector<int> C2(N+1);
    for (int c: C1)
        C2[c]++;
    //  S[x] = sum(C2[x:])
    vector<int> S(N+1);
    S[N] = C2[N];
    for (int i=N-1; i>=0; i--)
        S[i] = S[i+1]+C2[i];
    //  T[c] = sum(min(c, x) for c in C1)
    vector<int> T(N+1);
    for (int i=1; i<=N; i++)
        T[i] = T[i-1]+S[i];

    auto f = [&](int k, int n)
    {
        return n<=N && n<=T[n]/k;
    };

    int B = 1;
    while (B<N)
        B *= 2;

    for (int k=1; k<=N; k++)
    {
        int ans = 0;
        for (int b=B; b>=1; b/=2)
            if (f(k, ans+b))
                ans += b;
        cout<<ans<<endl;
    }
}
