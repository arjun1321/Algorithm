#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t-- > 0)
    {
         long int pos=0;
         long int sight = 0;
        long int n;
        cin>>n;
        int driver = 0;
        long int H[n];
        for(long int i=0; i<n; i++)
        {
            cin>>H[i];
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++ )
            {

                if(H[j] < H[j-1] && H[j] < H[j+1])
                    driver++;

                if(H[j] < H[i])
                {
                    driver++;
                }
                if(H[j] >= H[i])
                {
                    driver++;
                    break;
                }

            }
            for(int j=i-1; j>=0; j--)
            {
                if(H[j] < H[i])
                driver++;
                if(H[j] >= H[i])
                {
                    driver++;
                    break;
                }
            }

            long int sig = driver * i+1;
            if(sig > sight)
            {
                sight = sig;
                pos = i;
            }
        }
        cout<<pos+1<<endl;
    }
    return 0;
}
