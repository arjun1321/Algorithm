#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int m,n;
        cin>>m>>n;
        for(long int i = m; i <= n; i++)
        {
            long int root = sqrt(i);
            long int count = 0;
            if(i==1)
                count++;
            long int j=2;
            while(j<=root)
            {
                if(i%j == 0)
                {
                    if(i!=j)
                        count++;
                }
                j++;
            }
            if(count == 0)
                cout<<i<<endl;
        }

        cout<<endl;
    }
    return 0;
}
