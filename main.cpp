#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account a("12345");
    a.addOperation(50);
    cout << a;


    return 0;
}
