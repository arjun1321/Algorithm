#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int isOperand(char ch)
{
    return (ch >='a' && ch<='z') || (ch >= 'A' && ch <= 'Z');
}

int PrecedenseTest(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int main()
{

   int t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;
       vector <char> output;
       stack <char> charStack;
       for(int i=0; i<s.length(); i++)
       {
           if(isOperand(s[i]))
           {
               output.push_back(s[i]);

           }
           else if(s[i] == '(')
           {
               charStack.push(s[i]);
           }
           else if(s[i] == ')')
           {
               while(charStack.top() != '(')
                {
                    output.push_back(charStack.top());
                    charStack.pop();
                }

                if(!charStack.empty() && charStack.top() != '(')
                    return -1;
                else
                    charStack.pop();


           }
           else
           {

               if(charStack.empty() ||  PrecedenseTest(s[i]) > PrecedenseTest(charStack.top()))
               {
                   charStack.push(s[i]);
               }
               else
               {
                   while(PrecedenseTest(s[i]) < PrecedenseTest(charStack.top()))
                   {
                       output.push_back(charStack.top());
                       charStack.pop();
                   }
                   charStack.push(s[i]);
               }
           }
       }
       while(!charStack.empty())
       {
           output.push_back(charStack.top());
           charStack.pop();
       }

       for(int i=0; i<output.size(); i++)
       {
           cout<<output.at(i);
       }
       cout<<endl;
   }

    return 0;
}
