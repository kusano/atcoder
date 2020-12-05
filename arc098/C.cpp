#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K, Q;
    cin>>N>>K>>Q;
    vector<int> A(N);
    for (int &a: A)
        cin>>a;

    int oo = 1000000000;
    int ans = oo;
    for (int y=0; y<N; y++)
    {
        int Y = A[y];
        vector<int> S, T;
        for (int i=0; i<=N; i++)
        {
            if (i==N || A[i]<Y)
            {
                sort(T.begin(), T.end());
                for (int j=0; j<(int)T.size()-K+1; j++)
                    S.push_back(T[j]);
                T.clear();
            }
            if (i<N && A[i]>=Y)
                T.push_back(A[i]);
        }
        sort(S.begin(), S.end());
        if ((int)S.size()>=Q)
        {
            int X = S[Q-1];
            ans = min(ans, X-Y);
        }
    }
    cout<<ans<<endl;
}
