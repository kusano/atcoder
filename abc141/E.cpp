#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    string S;
    cin>>S;

    vector<vector<int>> T(N+1, vector<int>(N+1));
    int ans = 0;
    for (int i=N-1; i>=0; i--)
        for (int j=0; j<N; j++)
        {
            if (S[i]==S[j])
                T[i][j] = T[i+1][j+1]+1;
            else
                T[i][j] = 0;
            ans = max(ans, min(T[i][j], abs(i-j)));
        }
    cout<<ans<<endl;
}
