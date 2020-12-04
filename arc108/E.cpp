#include <iostream>
#include <vector>
#include <functional>
using namespace std;

long long powmod(long long a, long long b, long long m)
{
    long long r = 1;
    for (; b>0; b>>=1, a=a*a%m)
        if (b&1)
            r = r*a%m;
    return r;
}

int main()
{
    int N;
    cin>>N;
    vector<int> a(N+2);
    for (int i=0; i<N; i++)
        cin>>a[i+1];
    a[N+1] = N+1;

    long long M = 1000000007;
    vector<long long> I(N+1);
    for (int i=1; i<=N; i++)
        I[i] = powmod(i, M-2, M);

    vector<vector<long long>> T0(N+2, vector<long long>(N+2));
    vector<vector<long long>> T1(N+2, vector<long long>(N+2));
    for (int d=1; d<=N+1; d++)
        for (int i=0; i+d<=N+1; i++)
        {
            if (a[i]>a[i+d])
                continue;

            int c = 0;
            long long s = 0;
            for (int j=i+1; j<i+d; j++)
                if (a[i]<a[j] && a[j]<a[i+d])
                {
                    c++;
                    s += T0[i][j] + T1[i+d][j];
                }
            if (c==0)
                T0[i][i+d] = T1[i+d][i] = 0;
            else
                T0[i][i+d] = T1[i+d][i] = (1+s*I[c])%M;
        }
    cout<<T0[0][N+1]<<endl;
}
