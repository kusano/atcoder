#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> P(100001, true);
    P[0] = P[1] = false;
    for (int i=2; i<=100000; i++)
        if (P[i])
            for (int j=i+i; j<=100000; j+=i)
                P[j] = false;

    vector<int> S(100001);
    for (int i=1; i<=100000; i++)
        if (i%2!=0 && P[i] && P[(i+1)/2])
            S[i] = S[i-1]+1;
        else
            S[i] = S[i-1];

    int Q;
    cin>>Q;
    for (int i=0; i<Q; i++)
    {
        int l, r;
        cin>>l>>r;
        cout<<S[r]-S[l-1]<<endl;
    }
}
