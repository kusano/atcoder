#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string first, last;
    cin>>first>>last;
    int N;
    cin>>N;
    vector<string> s(N);
    for (string &t: s)
        cin>>t;

    if (first==last)
    {
        cout<<0<<endl;
        cout<<first<<endl;
        cout<<last<<endl;
        return 0;
    }

    s.push_back(first);
    s.push_back(last);
    vector<int> P(N+2, -1);
    vector<int> Q;
    P[N] = -2;
    Q.push_back(N);
    for (int q=0; q<(int)Q.size(); q++)
        for (int i=0; i<N+2; i++)
            if (P[i]==-1)
            {
                int c = 0;
                for (int j=0; j<(int)s[i].size(); j++)
                    if (s[i][j]!=s[Q[q]][j])
                        c++;
                if (c==1)
                {
                    P[i] = Q[q];
                    Q.push_back(i);
                }
            }

    if (P[N+1]==-1)
        cout<<-1<<endl;
    else
    {
        vector<string> ans;
        for (int p=N+1; p!=-2; p=P[p])
            ans.push_back(s[p]);
        reverse(ans.begin(), ans.end());
        cout<<ans.size()-2<<endl;
        for (string a: ans)
            cout<<a<<endl;
    }    
}
