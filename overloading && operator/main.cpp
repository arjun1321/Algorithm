#include <iostream>

using namespace std;

class andoperator
{
    int x;
    int y;
public:
    andoperator(){}
    andoperator(int a,int b)
    {
        x=a;
        y=b;
    }
   int operator&&(andoperator);
};
int andoperator::operator&&(andoperator s)
{
    if((x>s.x||y>s.y)==1)
        return 0;
        else return 1;
}
int main()
{
    andoperator ob1,ob2;
    ob1=andoperator(3,3);
    ob2=andoperator(5,4);
    if(ob1&&ob2)
       {
           cout<<"&& operator overloading:\n";
           cout<<"Now this becomes NOR operator:\n";
       }

    return 0;
}
