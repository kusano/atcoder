#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> x(N), y(N);
    for (int i=0; i<N; i++)
        cin>>x[i]>>y[i];
    
    int c = 0;
    for (int i=0; i<N; i++)
    for (int j=0; j<i; j++)
    for (int k=0; k<j; k++)
    {
        long long x1 = x[j]-x[i];
        long long x2 = x[k]-x[i];
        long long y1 = y[j]-y[i];
        long long y2 = y[k]-y[i];
        long long s = x1*y2-x2*y1;
        if (s!=0 && s%2==0)
            c++;
    }
    cout<<c<<endl;
}
