#include <iostream>
#include <vector>
using namespace std;

int main()
{
    static double T[101][101][101];

    for (int i=0; i<=100; i++)
        for (int j=0; j<=100; j++)
            T[i][j][100] = T[i][100][j] = T[100][i][j] = 0.;

    for (int a=99; a>=0; a--)
    for (int b=99; b>=0; b--)
    for (int c=99; c>=0; c--)
        if (a+b+c>0)
        {
            int s=a+b+c;
            T[a][b][c] = 1. +
                T[a+1][b][c]*a/s +
                T[a][b+1][c]*b/s +
                T[a][b][c+1]*c/s;
        }

    int A, B, C;
    cin>>A>>B>>C;
    printf("%.10f\n", T[A][B][C]);
}
