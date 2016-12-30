#include <iostream>

using namespace std;

int main()
{
    int n=10;
    long double N, T, more;
    while(n--)
    {
        cin>>T;
        cin>>more;
        N = (T - more)/2;
        cout<<N+more<<endl;
        cout<<N<<endl;
    }
    return 0;
}
