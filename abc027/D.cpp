#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    string S;
    cin>>S;

    int n = (int)S.size();
    vector<int> F(n), B(n);
    int t = 0;
    for (int i=0; i<n; i++)
    {
        if (S[i]=='+')
            t++;
        if (S[i]=='-')
            t--;
        F[i] = t;
    }
    t = 0;
    for (int i=n-1; i>=0; i--)
    {
        if (S[i]=='+')
            t++;
        if (S[i]=='-')
            t--;
        B[i] = t;
    }

    vector<pair<int, int>> T;
    for (int i=0; i<n; i++)
        if (S[i]=='M')
            T.push_back(make_pair(F[i]-B[i], i));
    sort(T.begin(), T.end());

    int m = (int)T.size();
    for (int i=0; i<m/2; i++)
        S[T[i].second] = '>';
    for (int i=m/2; i<m; i++)
        S[T[i].second] = '<';

    long long ans = 0;
    int p = 0;
    for (int i=0; i<n; i++)
    {
        if (S[i]=='+')
            ans += p;
        if (S[i]=='-')
            ans -= p;
        if (S[i]=='<')
            p--;
        if (S[i]=='>')
            p++;
    }
    cout<<ans<<endl;
}
