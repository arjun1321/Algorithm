#include <iostream>
#include <sstream>

using namespace std;

// Base class
class Employee {

    protected:
        string name;
        double pay;
    public:
        Employee() {
            name = "";
            pay = 0;
        }

        Employee(string empName, double payRate) {

            name = empName;
            pay = payRate;
        }

        string getName() {

            return name;
        }

        void setName(string empName) {
            name = empName;
        }

        double getPay() {
            return pay;
        }

        void setPay(double payRate) {
            pay = payRate;
        }

        string toString() {
            stringstream stm;
            stm << name << ": " << pay; // pay is double, convert it using stringstream.
            return stm.str();
        }

        double grossPay(int hours) {
            return pay * hours;
        }


};

// derived class

class Manager : public Employee {

private:
    bool salaried;

public:
    Manager(string name, double payRate, bool isSalaried)
            : Employee(name, payRate) // calling base class constructor.
            {
                salaried = isSalaried;
            }

            bool getSalaried() {
                return salaried;
            }

            double grossPay() {
                return pay;
            }

};

int main()
{
    Employee emp1("Mary Smith", 15.00);
    cout << "Employee name: " << emp1.getName() << endl;
    cout << "Employee pay rate: " << emp1.getPay() << endl;
    cout << "Employee gross pay: " << emp1.grossPay(40) << endl;
    Manager emp2("Bob Brown", 1500, true);
    cout << "Employee name: " << emp2.getName() << endl;
    cout << "Employee payRate: " << emp2.getPay() << endl;
    cout << "Emp2 Salaried? " << emp2.getSalaried() << endl;
    cout << "Employee gross pay: " << emp2.grossPay() << endl;


    return 0;
}
