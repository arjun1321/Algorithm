#include <iostream>

using namespace std;

class decrement
{
    int x;
public:
    decrement(){}
    decrement(int n)
    {
        x=n;
    }
    void operator--(void);
    void display(void);
};
void decrement::display(void)
{
    cout<<"The value is decremented by 2 by overloading -- operator\n";
    cout<<"value is "<<x<<"\n";
}
void decrement::operator--()
{
    x=x-2;
}
int main()
{
    int a=10;
    decrement num;
    cout<<"Entered value is 10:\n";
    num=decrement(a);
    --a;
    --num;
    num.display();
    cout<<"Normal decrement: \n"<<a;
    return 0;
}
