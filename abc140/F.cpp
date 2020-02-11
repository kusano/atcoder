#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> S(1<<N);
    for (int &s: S)
        cin>>s;

    sort(S.begin(), S.end());
    reverse(S.begin(), S.end());
    vector<int> U(1<<N, -1);
    U[0] = 0;
    for (int i=1; i<=N; i++)
    {
        int p = 0;
        for (int j=0; j<1<<N; j++)
            if (0<=U[j] && U[j]<i)
            {
                while (p<1<<N && (U[p]!=-1 || S[p]>=S[j]))
                    p++;
                if (p<1<<N)
                    U[p] = i;
            }
    }
    bool ans = true;
    for (int u: U)
        if (u==-1)
            ans = false;
    cout<<(ans ? "Yes" : "No")<<endl;
}
