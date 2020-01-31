#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<complex<double>> C(N);
    for (auto &c: C)
    {
        double x, y;
        cin>>x>>y;
        c = complex<double>(x, y);
    }

    double pi = acos(-1.0);

    long long r = 0;
    long long a = 0;
    for (int i=0; i<N; i++)
    {
        vector<double> V;
        for (int j=0; j<N; j++)
            if (j!=i)
                V.push_back(arg(C[j]-C[i]));
        
        sort(V.begin(), V.end());
        for (int i=0; i<N-1; i++)
            V.push_back(V[i]+2*pi);
        V.push_back(100.0);

        int k = 0;
        for (int j=0; j<N-1; j++)
        {
            while (V[k]-V[j]<pi/2.0-1e-9)
                k++;
            if (V[k]-V[j]<pi/2.0+1e-9)
                r++;
            a += k-j-1;
        }
    }
    long long tn = (long long)N*(N-1)*(N-2)/6;
    long long o = tn*3 - r - a;
    cout<<tn-o-r<<" "<<r<<" "<<o<<endl;
}
