#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Car
{
public:
  string Model;
  int Rental_rate;
  int Rental_dur;

  void Info()
  {
    cout << "enter car model: " << endl;
    cin.ignore();
    getline(cin, Model);

    bool isAlpha = true;

    for (char c : Model)
    {
      if (!isalpha(c) && !isspace(c))
      {
        isAlpha = false;
        break;
      }
    }
    if (!isAlpha)
    {
      cout << "invalid model name. try again";
      exit(1);
    }
    cout << "enter rental rate: " << endl;
    cin >> Rental_rate;
    cout << "enter rental duration: " << endl;
    cin >> Rental_dur;
  }
};

class Rate_Display : public Car
{
  int bill;

public:
  void Calc()
  {
    Info();
    cout << endl;
    bill = Rental_rate * Rental_dur;
    cout << "CAR DETAILS: " << endl;
    cout << "model: " << Model << endl;
    cout << "bill: " << bill << endl;
    cout << endl;
    cout << "your total bill is Rs. " << bill;
  }
};

int main()
{
  Rate_Display r1;
  r1.Calc();
}