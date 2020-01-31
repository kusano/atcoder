#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x[5][5];
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            cin>>x[i][j];

    int zn = 0;
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            if (x[i][j]==0)
                zn++;

    auto comp = [&](bool B[5][5])
    {
        int b = 0;
        int n = 0;
        for (int i=0; i<5; i++)
            for (int j=0; j<5; j++)
                if (x[i][j]==0)
                    b |= int(B[i][j])<<n++;
        return b;
    };

    auto uncomp = [&](int b, int c, bool B[5][5])
    {
        int n = 0;
        for (int i=0; i<5; i++)
            for (int j=0; j<5; j++)
                if (x[i][j]==0)
                    B[i][j] = bool(b>>n++&1);
                else
                    B[i][j] = x[i][j]<c;
    };

    long long M = 1000000007;

    vector<long long> T(1<<zn);
    T[0] = 1;
    for (int c=1; c<=25; c++)
    {
        vector<long long> P(1<<zn);
        P.swap(T);

        int cx = -1;
        int cy = -1;
        for (int i=0; i<5; i++)
            for (int j=0; j<5; j++)
                if (x[i][j]==c)
                {
                    cx = j;
                    cy = i;
                }

        for (int b=0; b<1<<zn; b++)
            if (P[b]!=0)
            {
                bool B[5][5];
                uncomp(b, c, B);

                if (cx>=0)
                {
                    if ((cx==0 || cx==4 || (B[cy][cx-1]^B[cy][cx+1])==0) &&
                        (cy==0 || cy==4 || (B[cy-1][cx]^B[cy+1][cx])==0))
                        T[b] = P[b];
                }
                else
                {
                    for (int i=0; i<5; i++)
                        for (int j=0; j<5; j++)
                            if (!B[i][j])
                            {
                                if ((i==0 || i==4 || (B[i-1][j]^B[i+1][j])==0) &&
                                    (j==0 || j==4 || (B[i][j-1]^B[i][j+1])==0))
                                {
                                    B[i][j] = true;
                                    int b2 = comp(B);
                                    T[b2] = (T[b2]+P[b])%M;
                                    B[i][j] = false;
                                }
                            }
                }
            }
    }

    cout<<T[(1<<zn)-1]<<endl;
}
