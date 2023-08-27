#include <iostream>
using namespace std;
using std::string;

class AbstractDep
{
  virtual void deposit() = 0;
};

class Bank
{
private:
  int Acc_number;
  string Name;
  int Balance = 150000;

  // constructor
public:
  Bank(int acc_no, string name)
  {
    Acc_number = acc_no;
    Name = name;
    // Balance=150000;
  }

  // encapsulation
  int getAccount()
  {
    return Acc_number;
  }

  string getName()
  {
    return Name;
  }

  int getBalance()
  {
    return Balance;
  }

public:
  void deposit()
  {
    int money;
    cout << "BALANCE: " << Balance << endl;
    cout << "enter amount: " << endl;
    cin >> money;
    Balance = Balance + money;
    cout << "total balance now is: " << Balance << endl;
  }

  void withdrawal()
  {
    int money;
    cout << "BALANCE: " << Balance << endl;
    cout << "enter amt to withdraw: " << endl;
    cin >> money;
    Balance = Balance - money;
    if (money > Balance)
    {
      cout << "you cannot withdraw due to lack of balance" << endl;
      exit(1);
    }
    else
    {
      cout << "amount left in account: " << Balance << endl;
    }
  }

  void display()
  {
    cout << "your bank bank details: " << endl;
    cout << "BALANCE: " << Balance << endl;
  }
};

int main()
{
  char ans = 'y';
  Bank per1 = Bank(1234, "Hannah");
  while (ans == 'y' || ans == 'Y')
  {
    int choice;
    cout << "1. deposit  2. withdraw  3. check balance" << endl;
    cout << "enter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      per1.deposit();
      break;

    case 2:
      per1.withdrawal();
      break;

    case 3:
      per1.display();
      break;

    default:
      cout << "invalid input. try again." << endl;
    }
    cout << "do you want to continue? y/n: ";
    cin >> ans;
  }
  return 0;
}