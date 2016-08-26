#include <iostream>

using namespace std;

int main()
{

    while(1)
    {
    int N;
    cin>>N;
    if(N == 0)
        break;

    long int count = 0;

    while(N)
    {
        count = count + (N * N);
        N--;
    }

    cout<<count<<endl;
    }
    return 0;
}
