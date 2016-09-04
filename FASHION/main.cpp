#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int n1;
        cin>>n1;
        int arr1[n1], arr2[n1];


        for(int i=0; i<n1; i++)
            cin>>arr1[i];
        for(int i=0; i<n1; i++)
            cin>>arr2[i];

        sort(arr1, arr1 + n1);
        sort(arr2, arr2 + n1);

        int count =0;

        for(int i=0; i<n1; i++)
        {
            count += (arr1[i] * arr2[i]);
        }
        cout<<count;
        cout<<endl;
    }
    return 0;
}
