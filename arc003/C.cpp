#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    vector<string> c(N);
    for (string &s: c)
        cin>>s;

    auto f = [&](double lim)
    {
        vector<vector<int>> T(N, vector<int>(M, -1));
        vector<pair<int, int>> Q;
        for (int y=0; y<N; y++)
            for (int x=0; x<M; x++)
                if (c[y][x]=='s')
                {
                    T[y][x] = 0;
                    Q.push_back(make_pair(x, y));
                }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int q=0; q<(int)Q.size(); q++)
        {
            int x = Q[q].first;
            int y = Q[q].second;
            for (int d=0; d<4; d++)
            {
                int tx = x + dx[d];
                int ty = y + dy[d];
                if (0<=tx && tx<M && 0<=ty && ty<N && T[ty][tx]==-1)
                {
                    if (c[ty][tx]=='g')
                        return true;
                    if (c[ty][tx]=='#')
                        continue;
                    if ((c[ty][tx]-'0')*pow(0.99, T[y][x]+1)<lim)
                        continue;
                    T[ty][tx] = T[y][x]+1;
                    Q.push_back(make_pair(tx, ty));
                }
            }
        }
        return false;
    };

    if (!f(0))
    {
        printf("-1\n");
        return 0;
    }

    double l = 0.;
    double r = 10.;
    for (int i=0; i<64; i++)
    {
        double m = (l+r)*.5;
        (f(m) ? l : r) = m;
    }
    printf("%.10f\n", l);
}
