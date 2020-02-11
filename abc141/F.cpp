#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> A(N);
    for (long long &a: A)
        cin>>a;

    vector<long long> C(60);
    for (int i=0; i<60; i++)
        for (long long a: A)
            C[i] += a>>i&1;

    vector<int> R;
    for (int i=59; i>=0; i--)
        if (C[i]>0 && C[i]%2==0)
            R.push_back(i);
    int h = (int)R.size();

    vector<vector<int>> M(h, vector<int>(N));
    for (int i=0; i<h; i++)
        for (int j=0; j<N; j++)
            M[i][j] = A[j]>>R[i]&1;

    int c = 0;
    for (int y=0; y<h; y++)
    {
        for (int x=c; x<N; x++)
            if (M[y][x]!=0)
            {
                for (int i=0; i<h; i++)
                    swap(M[i][x], M[i][c]);
                break;
            }
        if (M[y][c]!=0)
        {
            for (int x=0; x<N; x++)
                if (x!=c && M[y][x] != 0)
                    for (int i=0; i<h; i++)
                        M[i][x] ^= M[i][c];
            c++;
        }
    }

    long long ans = 0;
    for (long long a: A)
        ans ^= a;
    for (int y=0; y<h; y++)
    {
        int c = 0;
        for (int m: M[y])
            c += m;
        if (c%2!=0)
            ans += 1LL<<(R[y]+1);
    }
    cout<<ans<<endl;
}
