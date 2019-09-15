#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

#include <string>

using std::string;

typedef unsigned long Amount;

class BankAccout
{
private:
    string dep_name;
    string acc_num;
    Amount balance;
public:
    BankAccount();
    BankAccount(string & d_name, string & a_num, Amount bal);
    void depositing(Amount amount);
    bool withdraw(Amount amount);
    void show() const;
};
#endif