#include <iostream>


using namespace std;

int main()
{
    int M;
    cin>>M;
    int count = 0;

    while (M>0)
    {
        string s;
        cin>>s;

        int flag = 1;
        if(s.length() % 2 == 0)
        {
            for(int i=0,j=s.length()-1; i<j;)
            {
                if(s[i] == s[i+1])
                {
                    i = i+2;
                }
                else if(s[i] == s[j])
                {
                    i = i+1;
                    j = j-1;
                }
                else if(s[j] == s[j-1])
                {
                    j = j-2;
                }
                else
                {
                    flag = 0;
                    break;
                }

            }
        } else {flag = 0;}
        if(flag == 1)
        {
            count++;
        }
        M--;
    }
    cout<<count;
    return 0;
}
