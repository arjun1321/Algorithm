#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string str;
    while(t-- > 0)
    {
    cin>>str;
    for (int i = 0; i<str.length() / 2; )
    {
        cout<<str[i];
        i=i+2;
    }
    cout<<endl;
    }
    return 0;
}
