#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, P, Q, R;
    cin>>N>>M>>P>>Q>>R;
    vector<int> x(R), y(R), z(R);
    for (int i=0; i<R; i++)
    {
        cin>>x[i]>>y[i]>>z[i];
        x[i]--;
        y[i]--;
    }

    vector<int> T(M);
    int ans = 0;
    for (int b=0; b<1<<N; b++)
    {
        int c = 0;
        for (int i=0; i<N; i++)
            if (b>>i&1)
                c++;
        if (c==P)
        {
            for (int i=0; i<M; i++)
                T[i] = 0;
            for (int i=0; i<R; i++)
                if (b>>x[i]&1)
                    T[y[i]] += z[i];
            sort(T.begin(), T.end());
            int a = 0;
            for (int i=0; i<Q; i++)
                a += T[M-i-1];
            ans = max(ans, a);
        }
    }
    cout<<ans<<endl;
}
