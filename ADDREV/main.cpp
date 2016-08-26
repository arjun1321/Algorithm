#include <iostream>

using namespace std;

int main()
{
    long int N;
    cin>>N;
    while(N--)
    {
        long int x,y;
        cin>>x>>y;

        int arr1[50], arr2[50], res[50];

        int pos1 = -1;
        long int n=x;
        int mark  = 0;
        while(n)
        {

           int rem = n%10;
           if(rem == 0 && mark == 0)
           {
               n = n/10;
               continue;
           }
               mark = 1;
               pos1++;
               arr1[pos1] = rem;
                n = n/10;
        }

        int pos2 = -1;
        n=y;
        mark = 0;
        while(n)
        {
           int rem = n%10;
           if(rem == 0 && mark == 0)
           {
               n = n/10;
               continue;
           }
               mark = 1;
               pos2++;
               arr2[pos2] = rem;
                n = n/10;
        }

        int i=0;
        int carry = 0;
        mark = 0;
        while(pos1 != -1 && pos2 != -1)
        {
            int k = arr1[pos1] + arr2[pos2] + carry;
            int rem = k%10;
           if(rem == 0 && mark == 0)
           {
               carry = k/10;
            pos1--;
            pos2--;
            continue;
           }
           mark = 1;
           res[i] = rem;
               i++;

            carry = k/10;
            pos1--;
            pos2--;

        }
        while(pos1!=-1)
        {
            int k = arr1[pos1] + carry;
            int rem = k% 10;
            if(rem == 0 && mark == 0)
           {
               carry = k/10;
            pos1--;
            continue;
           }
           mark = 1;
               res[i] = rem;
               i++;
            carry = k/10;
            pos1--;
        }

        while(pos2!=-1)
        {
            int k = arr2[pos2] + carry;
            int rem = k % 10;
            if(rem == 0 && mark == 0)
           {
               carry = k/10;
            pos2--;
            continue;
           }
           mark = 1;
               res[i] = rem;
               i++;
            carry = k/10;
            pos2--;
        }
        if(carry == 0)
        {
            i--;
        }
        else
        {
            res[i] = carry;
        }

        for(int j=0; j<=i; j++)
        {
            cout<<res[j];
        }
        cout<<endl;

    }
    return 0;
}
