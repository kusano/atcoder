#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    vector<vector<int>> E(N);
    for (int i=0; i<M; i++)
    {
        int a, b;
        cin>>a>>b;
        E[a-1].push_back(b-1);
        E[b-1].push_back(a-1);
    }
    int Q;
    cin>>Q;
    vector<int> v(Q), d(Q), c(Q);
    for (int i=0; i<Q; i++)
    {
        cin>>v[i]>>d[i]>>c[i];
        v[i]--;
    }

    vector<int> A(N, -1);

    for (int i=0; i<=10; i++)
    {
        vector<int> VD(N, -1), VI(N, -1);
        for (int j=0; j<Q; j++)
            if (d[j]==i)
                VD[v[j]] = 0,
                VI[v[j]] = j;
        for (int j=0; j<i; j++)
        {
            vector<int> PVD = VD;
            vector<int> PVI = VI;

            for (int v=0; v<N; v++)
                if (PVD[v]==j && j<d[PVI[v]])
                    for (int e: E[v])
                        if (VI[e]<PVI[v])
                        {
                            VD[e] = j+1;
                            VI[e] = PVI[v];
                        }
        }
        for (int j=0; j<N; j++)
            A[j] = max(A[j], VI[j]);
    }

    for (int a: A)
        cout<<(a==-1 ? 0 : c[a])<<endl;   
}
