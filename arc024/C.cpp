#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N, K;
    cin>>N>>K;
    string S;
    cin>>S;

    vector<vector<int>> C(N-K+1);
    vector<int> c(26);
    for (int i=0; i<K; i++)
        c[S[i]-'a']++;
    C[0] = c;
    for (int i=1; i+K<=N; i++)
    {
        c[S[i-1]-'a']--;
        c[S[i+K-1]-'a']++;
        C[i] = c;
    }

    string ans = "NO";
    set<vector<int>> SC;
    for (int i=0; i+2*K<=N; i++)
    {
        SC.insert(C[i]);
        if (SC.count(C[i+K])!=0)
            ans = "YES";
    }
    cout<<ans<<endl;
}
