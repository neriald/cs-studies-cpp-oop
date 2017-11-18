#include <iostream>
#include "Account.h"

Account::Account(const Account &a)
{
    number = "" ;
    balance = a.balance;
    ops = a.ops;
}
Account::~Account()
{
    ops.clear();
}

Account& Account::operator=(const Account &a)
{
    if(this!=&a)
    {
        number="";
        balance=a.balance;
        ops=a.ops;
    }
    return *this;
}

string Account::get_number() const
{
    return number;
}

double Account::get_balance()
{
    return balance;
}

ostream& operator << (ostream &out, const Account &a)
{
    out << "Acc. number: " << a.number << endl;
    out << "Balance: " << a.balance << endl;
    out << "Last operation: " << a.ops[0] << endl;
}

