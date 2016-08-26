#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        long int x;
        long int y;
        cin>>x>>y;

        if(x%2 == 0 && x == y)
        {
            cout<<2*x<<endl;
        }
        else if(x%2 == 0 && y == x-2)
        {
            cout<<x+y<<endl;
        }
        else if(x%2 != 0 && x == y)
        {
            cout<<x+y-1<<endl;
        }
        else if(x%2 != 0 && y == x-2)
        {
            cout<<x+y-1<<endl;
        }
        else
        {
            cout<<"No Number"<<endl;
        }
    }
    return 0;
}
