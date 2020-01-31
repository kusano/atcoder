#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> L(N);
    for (int &l: L)
        cin>>l;

    sort(L.begin(), L.end());
    int ans = 0;
    for (int i=0; i<N; i++)
    {
        int j = i+1;
        for (int k=i+2; k<N; k++)
        {
            while (j<k && L[i]+L[j]<=L[k])
                j++;
            ans += k-j;
        }
    }
    cout<<ans<<endl;
}
