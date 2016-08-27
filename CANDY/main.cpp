#include <iostream>

using namespace std;

int main()
{

    int T;
    cin>>T;
    while(T != -1)
    {
        int arr[T];
        int count = 0;
        for(int i=0; i<T; i++)
        {
            cin>>arr[i];
            count += arr[i];
        }

        float avg = (float)count/T;
        int avgs = (int)avg;

        int move = 0;

        if(avgs < avg)
            cout<<-1<<endl;
        else
        {
            for(int i=0; i<T; i++)
        {
            if(arr[i] < avg)
                move += (avg - arr[i]);
        }
        cout<<move<<endl;
        }

cin>>T;
    }


    return 0;
}
