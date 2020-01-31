#include <iostream>
#include <vector>
using namespace std;

template<class T>
T gcd(T a, T b)
{
    while (a > 0)
    {
        T t = a;
        a = b%a;
        b = t;
    }
    return b;
}

int main()
{
    long long A, B;
    cin>>A>>B;
    long long C = gcd(A, B);

    long long ans = 1;
    for (long long f=2; f*f<=C; f++)
        if (C%f==0)
        {
            ans++;
            while (C%f==0)
                C /= f;
        }
    if (C>1)
        ans++;
    cout<<ans<<endl;
}
