#include <iostream>
#include <vector>
#include <functional>
#include <set>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    vector<vector<int>> E(N), C(N);
    vector<set<int>> S(N);
    vector<set<int>> SE(N);
    for (int i=0; i<M; i++)
    {
        int u, v, c;
        cin>>u>>v>>c;
        u--, v--, c--;
        if (SE[u].count(v)==0)
        {
            E[u].push_back(v);
            C[u].push_back(c);
            S[u].insert(c);
            SE[u].insert(v);

            E[v].push_back(u);
            C[v].push_back(c);
            S[v].insert(c);
            SE[v].insert(u);
        }
    }

    vector<int> V(N, -1);
    function<void(int, int)> f = [&](int p, int c)
    {
        if (c==-1)
        {
            int x = 0;
            while (S[p].count(x)>0)
                x++;
            V[p] = x;
        }
        else
        {
            V[p] = c;
        }

        for (int i=0; i<(int)E[p].size(); i++)
            if (V[E[p][i]]==-1)
                f(E[p][i], C[p][i]==V[p] ? -1 : C[p][i]);
    };
    f(0, -1);

    for (int v: V)
        cout<<v+1<<endl;
}
