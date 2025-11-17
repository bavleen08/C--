#include <iostream>
using namespace std;

// Create a class BankAccount with private attributes accountNumber and balance. Implement public methods deposit(), withdraw(), and getBalance() to manage the account.
class BankAccount{
   int accountNumber;
   double balance;
public:
    BankAccount(int accnum, double bal){
        accountNumber = accnum;
        balance = bal;
    }
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
        if(amount <= balance){
            balance -= amount;
        } else{
            cout << "Not enough balance for this withdrawl" << endl;
        }
    }
    double getbalance(){
        return balance;
    }
};

int main(){
    BankAccount b1(123456, 500);
    b1.deposit(200);
    b1.withdraw(60000);
    cout << "Current balance is: " << b1.getbalance() << endl;
    return 0;
}