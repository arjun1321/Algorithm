#include <iostream>

using namespace std;

int main()
{

    char str[101];
    int flag = 1;
    scanf("%s",str);
    int n = strlen(str);
    for(int i=0,j=n-1; i<j; i++,j--)
    {
        if(str[i] != str[j])
        {
            flag = 0;
        }
    }

    if(flag == 0)
        printf("%s","NO");
    else
        printf("%s","YES");
    return 0;
}
