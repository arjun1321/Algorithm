#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        long int b;
        cin>>a>>b;
        int exp;
        int lasta = a % 10;
        if(b == 0 )
        {
            cout<<1<<endl;
            continue;
        }
        int res = b % 4;

        if(res == 0)
        {
            exp = 4;
        }
        if(res !=0 )
        {
            exp = res;
        }

        int ldigit = pow(lasta, exp);
        int lastDigit = ldigit % 10;

        cout<<lastDigit<<endl;

    }
    return 0;
}
