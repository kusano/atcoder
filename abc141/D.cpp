#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    vector<int> A(N);
    for (int &a: A)
        cin>>a;

    priority_queue<int> Q;
    for (int a: A)
        Q.push(a);
    for (int i=0; i<M; i++)
    {
        int a = Q.top();
        Q.pop();
        Q.push(a/2);
    }
    long long ans = 0;
    for (; !Q.empty(); Q.pop())
        ans += Q.top();
    cout<<ans<<endl;
}
