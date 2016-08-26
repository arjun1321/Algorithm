#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
        int x, y, z;
        cin>>x>>y>>z;

        if(!x && !y && !z)
            break;

        if((y-x) == (z-y))
            cout<<"AP "<<z + (y-x)<<endl;
        else
            cout<<"GP "<< z * (y/x)<<endl;
    }
    return 0;
}
