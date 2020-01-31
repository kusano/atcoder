#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;

    vector<vector<int>> E(N);
    for (int i=0; i<M; i++)
    {
        int A, B;
        cin>>A>>B;
        E[A-1].push_back(B-1);
    }

    vector<int> C;
    vector<bool> F(N);
    bool f = false;

    function<void(int, int)> BT = [&](int c, int s)
    {
        if (F[c])
        {
            if (c==s)
                f = true;
            return;
        }

        C.push_back(c);
        F[c] = true;

        for (int e: E[c])
        {
            BT(e, s);
            if (f)
                break;
        }

        if (!f)
            C.pop_back();
    };

    for (int s=0; s<N && !f; s++)
    {
        for (int i=0; i<N; i++)
            F[i] = false;
        BT(s, s);
    }

    if (C.size()<=1)
    {
        cout<<-1<<endl;
        return 0;
    }

    vector<bool> F2(N);
    vector<int> C2;

    while (true)
    {
        for (int i=0; i<N; i++)
            F2[i] = false;
        for (int c: C)
            F2[c] = true;

        int ef = -1;
        int et = -1;
        for (int i=0; i<(int)C.size() && ef==-1; i++)
            for (int e: E[C[i]])
                if (F2[e] &&
                    e!=C[(i+1)%C.size()])
                {
                    ef = C[i];
                    et = e;
                    break;
                }

        if (ef==-1)
            break;

        C2.clear();
        for (int c: C)
        {
            if (c==ef)
            {
                int s = 0;
                for (int c: C)
                {
                    if (s==0)
                        C2.push_back(c);
                    if (c==ef)
                        s=1;
                    if (c==et)
                        s=2;
                    if (s==2)
                        C2.push_back(c);
                }
                break;
            }
            else if (c==et)
            {
                int s = 0;
                for (int c: C)
                {
                    if (c==et)
                        s = 1;
                    if (s==1)
                        C2.push_back(c);
                    if (c==ef)
                        s = 2;
                }
                break;
            }
        }
        C.swap(C2);
    }

    /*
    if (C.size()<=1)
    {
        return -1;
    }
    for (int i=0; i<(int)C.size(); i++)
    {
        bool ok = false;
        for (int e: E[C[i]])
            if (e==C[(i+1)%C.size()])
                ok = true;
        if (!ok)
            return -1;
    }
    */

    cout<<C.size()<<endl;
    for (int c: C)
        cout<<c+1<<endl;
}
