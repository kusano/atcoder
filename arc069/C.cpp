#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> a(N);
    for (int &x: a)
        cin>>x;

    map<int, int> MX;
    map<int, int> MN;
    for (int x=0; x<N; x++)
    {
        if (MX.count(a[x])==0)
            MX[a[x]] = x;
        MN[a[x]]++;
    }

    vector<int> V(1, 0);
    for (auto it: MX)
        V.push_back(it.first);
    sort(V.begin(), V.end());
    
    int n = 0;
    int x = N;
    vector<long long> ans(N);
    for (int i=(int)V.size()-1; i>0; i--)
    {
        x = min(x, MX[V[i]]);
        n += MN[V[i]];
        ans[x] += (long long)n*(V[i]-V[i-1]);
    }
    for (long long a: ans)
        cout<<a<<endl;
}
