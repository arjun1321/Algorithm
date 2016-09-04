#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n)
    {
        string s;
        cin>>s;

        int l;
        l = (2*n) - 1;
        int m=1;

        for(int i=0; i<n; i++)
        {
            for(int j=i; j<s.length(); )
            {
                cout<<s[j];
                j = j+l;
                if(j<s.length())
                    cout<<s[j];
                j = j+m;
            }
            l = l-2;
            m = m+2;

        }

        cout<<endl;
        cin>>n;
    }
    return 0;
}
