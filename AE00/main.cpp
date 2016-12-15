#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int l=2, b=2;
    int count = n;
    while((b*l) <= n)
    {

        count++;
        l++;
        if((b*l) > n)
        {
            l=b+1;
            b++;
        }


    }
    cout<<count;

    return 0;
}
