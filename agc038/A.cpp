#include <iostream>
using namespace std;

int main()
{
    int H, W, A, B;
    cin>>H>>W>>A>>B;
    for (int y=0; y<H; y++)
    {
        for (int x=0; x<W; x++)
            cout<<char('0'+(x<A^y<B));
        cout<<endl;
    }
}
