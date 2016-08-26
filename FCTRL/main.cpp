#include <iostream>

using namespace std;

int main()
{
    long int T;
    cin>>T;
    while(T--)
    {
        long int N;
        cin>>N;

        long int k = 5;
        long int count = 0;
        while(k<=N)
        {
            int n = N / k;
            count = count + n;
            k = k * 5;
        }
        cout<<count<<endl;
    }
    return 0;
}
