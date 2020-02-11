#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main()
{
    int H, W;
    cin>>H>>W;
    vector<string> A(H);
    for (string &a: A)
        cin>>a;

    vector<vector<pair<int, int>>> V(H*W);
    for (int y=0; y<H; y++)
        for (int x=0; x<W; x++)
            if (A[y][x]=='#')
                V[0].push_back(make_pair(x, y));
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int d=0; d<W*H; d++)
    {
        for (auto p: V[d])
        {
            int x = p.first;
            int y = p.second;
            for (int i=0; i<4; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (0<=tx && tx<W && 0<=ty && ty<H && A[ty][tx]=='.')
                {
                    A[ty][tx] = '#';
                    V[d+1].push_back(make_pair(tx, ty));
                }
            }
        }
    }
    for (int d=W*H-1; d>=0; d--)
        if (!V[d].empty())
        {
            cout<<d<<endl;
            break;
        }
}
