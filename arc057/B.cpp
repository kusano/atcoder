#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int N, K;
    cin>>N>>K;
    vector<int> a(N);
    for (int &t: a)
        cin>>t;

    int s = 0;
    for (int t: a)
        s += t;
    if (s==K)
    {
        cout<<1<<endl;
        return 0;
    }

    int oo = 1000000001;
    vector<int> T(N+1, oo);
    T[0] = 0;
    T[1] = 1;
    s = a[0];
    for (int i=1; i<N; i++)
    {
        vector<int> P = T;
        for (int j=1; j<=i+1; j++)
            if (P[j-1]!=s && P[j-1]<oo)
                T[j] = min(T[j], P[j-1]+int((long long)a[i]*P[j-1]/s)+1);
        s += a[i];
    }

    for (int i=N; i>=0; i--)
        if (K>=T[i])
        {
            cout<<i<<endl;
            break;
        }
}
