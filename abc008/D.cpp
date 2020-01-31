#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int W, H;
    cin>>W>>H;
    int N;
    cin>>N;
    vector<int> X(N), Y(N);
    for (int i=0; i<N; i++)
    {
        cin>>X[i]>>Y[i];
        X[i]--;
        Y[i]--;
    }

    vector<int> SX = X;
    vector<int> SY = Y;
    sort(SX.begin(), SX.end());
    sort(SY.begin(), SY.end());
    vector<vector<bool>> F(N, vector<bool>(N));
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++)
            for (int i=0; i<N; i++)
                if (SX[x]==X[i] && SY[y]==Y[i])
                    F[y][x] = true;

    vector<vector<vector<vector<int>>>> memo(N,
        vector<vector<vector<int>>>(N,
            vector<vector<int>>(N,
                vector<int>(N, -1))));
    function<int(int, int, int, int)> f = [&](int x1, int y1, int x2, int y2)
    {
        if (x1>x2 || y1>y2)
            return 0;

        if (memo[x1][y1][x2][y2] >= 0)
            return memo[x1][y1][x2][y2];

        int ans = 0;
        int t =
            + (x2==N-1 ? W : SX[x2+1]) - (x1==0 ? -1 : SX[x1-1]) - 1
            + (y2==N-1 ? H : SY[y2+1]) - (y1==0 ? -1 : SY[y1-1]) - 1
            - 1;
        for (int y=y1; y<=y2; y++)
        for (int x=x1; x<=x2; x++)
            if (F[y][x])
                ans = max(ans,
                    t
                    + f(x1,  y1,  x-1, y-1)
                    + f(x1,  y+1, x-1, y2)
                    + f(x+1, y+1, x2,  y2)
                    + f(x+1, y1,  x2,  y-1));
        return memo[x1][y1][x2][y2] = ans;
    };
    cout<<f(0, 0, N-1, N-1)<<endl;
}
