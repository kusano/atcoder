#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

//  E[i]: vertexes which can be reased from i
//  W[i]: their weight
template<class T>
vector<T> dijkstra(vector<vector<int>> E, vector<vector<T>> W, int s, T inf)
{
    int n = (int)E.size();

    vector<T> D(n, inf);
    typedef pair<T,int> P;
    priority_queue<P,vector<P>,greater<P>> Q;

    D[s] = T();
    Q.push(make_pair(D[s], s));

    while (!Q.empty())
    {
        T d = Q.top().first;
        int p = Q.top().second;
        Q.pop();
        if (d > D[p])
            continue;
        for (int i=0; i<(int)E[p].size(); i++)
        {
            int t = E[p][i];
            if (d+W[p][i] < D[t])
                D[t] = d+W[p][i],
                Q.push(make_pair(D[t], t));
        }
    }
    return D;
}

#include <iostream>

int main()
{
    int H, W;
    cin>>H>>W;
    vector<string> a(H);
    for (string &t: a)
        cin>>t;

    vector<vector<int>> E(W*H+26), We(W*H+26);
    int S, G;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int y=0; y<H; y++)
    for (int x=0; x<W; x++)
        if (a[y][x]!='#')
        {
            if (a[y][x]=='S')
                S = y*W+x;
            if (a[y][x]=='G')
                G = y*W+x;

            for (int d=0; d<4; d++)
            {
                int tx = x+dx[d];
                int ty = y+dy[d];
                if (0<=tx && tx<W && 0<=ty && ty<H)
                {
                    E[y*W+x].push_back(ty*W+tx);
                    We[y*W+x].push_back(1);
                }
            }

            if ('a'<=a[y][x] && a[y][x]<='z')
            {
                E[y*W+x].push_back(W*H+a[y][x]-'a');
                We[y*W+x].push_back(1);
                E[W*H+a[y][x]-'a'].push_back(y*W+x);
                We[W*H+a[y][x]-'a'].push_back(0);
            }
        }

    int ans = dijkstra(E, We, S, W*H)[G];
    cout<<(ans<W*H ? ans : -1)<<endl;
}
