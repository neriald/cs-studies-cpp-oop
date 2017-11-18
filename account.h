#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
    string number;
    double balance;
    vector <double> ops;

public:

    Account(string _number=""): number(_number), balance(0){}
    Account(const Account &a); // Account c(a); yazýlabiliyor sayesinde c hesabý a nýn kopyasý oluyor...
    ~Account();

    Account& operator = (const Account &a); // makes possible to write a=b;

    string get_number() const;
    double get_balance();

    void addOperation(double op)
    {
        ops.push_back(op);
        balance += op;
    }

    double getIncome()
    {
        double sum=0;
        for(int i=0; i<ops.size(); i++)
        {
            if(ops[i]>0)
                sum+=ops[i];
        }
        return sum;
    }


    void getOutcome()
    {
        double sum=0;
        for(int i=0; i<ops.size(); i++)
        {
            if(ops[i]<0)
                sum+=ops[i];
        }
    }


    double operator[](int i) const // right now it only calls i'th elementh with cout << a[i] if it was double& operator.... it we would be able to change i'th vector too like a[i]=5;
    {
        if(i<ops.size())
            return ops[i];
        else
            throw string("die mothefucka");
    }
    void set_number(string _num);

    friend ostream& operator << (ostream &out, const Account &a);
};
