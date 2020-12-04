#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<string> S(N);
    for (string &s: S)
        cin>>s;

    int ans = 0;
    for (int A=0; A<N; A++)
    {
        bool ok = true;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                if (S[(i+A)%N][j] != S[(j+A)%N][i])
                    ok = false;
        if (ok)
            ans += N;
    }
    cout<<ans<<endl;
}
