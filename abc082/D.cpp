#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(vector<int> v, int g)
{
    int s = 0;
    for (int x: v)
        s += x;
    if (g<-s || s<g)
        return false;

    vector<bool> T(2*s+1);
    T[s] = true;
    for (int x: v)
    {
        vector<bool> P(2*s+1);
        P.swap(T);
        for (int i=-s; i<=s; i++)
            if (P[i+s])
                T[i-x+s] = T[i+x+s] = true;
    }
    return T[g+s];
}

int main()
{
    string s;
    cin>>s;
    int x, y;
    cin>>x>>y;

    int n = (int)s.size();
    int sx = 0;
    while (sx<n && s[sx]=='F')
        sx++;
    int c = 0;
    int l = 0;
    vector<int> vx;
    vector<int> vy;
    for (int i=sx; i<=n; i++)
    {
        if (i==n || s[i]=='T')
        {
            if (l>0)
                (c%2==0 ? vx : vy).push_back(l);
            l = 0;
            c++;
        }
        else
            l++;
    }

    if (check(vx, x-sx) && check(vy, y))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
