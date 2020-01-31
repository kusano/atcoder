#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    long long W;
    cin>>N>>W;
    long long w0 = -1;
    vector<long long> v[4];
    for (int i=0; i<N; i++)
    {
        long long tw, tv;
        cin>>tw>>tv;
        if (w0==-1)
            w0 = tw;
        v[tw-w0].push_back(tv);
    }

    for (int i=0; i<4; i++)
    {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }

    vector<long long> s[4];
    for (int i=0; i<4; i++)
    {
        s[i].resize(v[i].size()+1);
        for (int j=0; j<(int)v[i].size(); j++)
            s[i][j+1] = s[i][j]+v[i][j];
    }

    long long ans = 0;
    long long n[4];
    for (n[0]=0; n[0]<=v[0].size(); n[0]++)
    for (n[1]=0; n[1]<=v[1].size(); n[1]++)
    for (n[2]=0; n[2]<=v[2].size(); n[2]++)
    {
        long long t = n[0]*w0 + n[1]*(w0+1) + n[2]*(w0+2);
        if (t<=W)
        {
            n[3] = min((long long)v[3].size(), (W-t)/(w0+3));
            long long a = 0;
            for (int i=0; i<4; i++)
                a += s[i][n[i]];
            ans = max(ans, a);
        }
    }
    cout<<ans<<endl;
}
