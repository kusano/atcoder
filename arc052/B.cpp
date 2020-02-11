#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int N, Q;
    cin>>N>>Q;
    vector<double> X(N), R(N), H(N);
    for (int i=0; i<N; i++)
        cin>>X[i]>>R[i]>>H[i];

    double pi = acos(-1.0);

    for (int i=0; i<Q; i++)
    {
        double A, B;
        cin>>A>>B;
        double ans = 0;
        for (int j=0; j<N; j++)
        {
            if (A<X[j]+H[j])
            {
                double h = min(H[j], X[j]+H[j]-A);
                double r = R[j]/H[j]*h;
                ans += r*r*pi*h/3.;
            }
            if (B<X[j]+H[j])
            {
                double h = min(H[j], X[j]+H[j]-B);
                double r = R[j]/H[j]*h;
                ans -= r*r*pi*h/3.;
            }
        }
        printf("%.6f\n", ans);
    }
}
