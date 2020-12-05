#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int A, B;
    cin>>A>>B;

    map<int, int> M;
    for (int C=B+1; C<=A; C++)
    {
        int t = C;
        for (int f=2; f*f<=t; f++)
        {
            while (t%f==0)
            {
                t /= f;
                M[f]++;
            }
        }
        if (t>1)
            M[t]++;
    }

    long long ans = 1;
    for (auto m: M)
        ans = ans*(m.second+1)%1000000007;
    cout<<ans<<endl;
}
