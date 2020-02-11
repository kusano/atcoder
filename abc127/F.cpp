#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int Q;
    cin>>Q;
    priority_queue<long long> QL, QR;
    long long AL = 0;
    long long AR = 0;
    long long B = 0;

    for (int i=0; i<Q; i++)
    {
        int q;
        cin>>q;
        if (q==1)
        {
            long long a, b;
            cin>>a>>b;
            if (QL.empty() || a<=QL.top())
            {
                QL.push(a);
                AL += a;
            }
            else
            {
                QR.push(-a);
                AR += a;
            }
            if (QL.size() > QR.size()+1)
            {
                a = QL.top();
                QL.pop();
                AL -= a;
                QR.push(-a);
                AR += a;
            }
            if (QR.size() > QL.size())
            {
                a = -QR.top();
                QR.pop();
                AR -= a;
                QL.push(a);
                AL += a;
            }
            B += b;
        }
        else
        {
            long long x = QL.top();
            long long f = QL.size()*x - AL + AR - QR.size()*x + B;
            cout<<x<<" "<<f<<endl;
        }
    }
}
