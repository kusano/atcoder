#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> A(N);
    for (int &a: A)
        cin>>a;

    vector<int> ZN(N+1);
    ZN[N-1] = A[N-1]==0 ? 1 : 0;
    for (int i=N-2; i>=0; i--)
        if (A[i]==0)
            ZN[i] = ZN[i+1]+1;

    long long ans = 0;
    for (int i=0; i<N; i++)
    {
        int x = 0;
        int s = 0;
        int p = i;
        while (true)
        {
            if (p>=N)
                break;
            if (A[p]==0)
                p += ZN[p];
            if (p>=N)
                break;
            x ^= A[p];
            s += A[p];
            if (x!=s)
                break;
            p++;
        }
        ans += p-i;
    }
    cout<<ans<<endl;
}
