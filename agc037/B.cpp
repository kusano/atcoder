#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin>>N;
    string S;
    cin>>S;

    int T[8] = {};
    T[0] = N;
    long long ans = 1;
    int A[] = {0b110, 0b101, 0b011, 0b100, 0b010, 0b001, 0b000};
    for (char s: S)
    {
        int t = 0;
        switch (s)
        {
            case 'R': t = 0b100; break;
            case 'G': t = 0b010; break;
            case 'B': t = 0b001; break;
        }
        int a;
        for (int i=0; i<7; i++)
            if ((A[i]&t)==0 && T[A[i]]>0)
            {
                a = A[i];
                break;
            }
        ans = ans*T[a]%998244353;
        T[a]--;
        T[a|t]++;
    }
    cout<<ans<<endl;
}
