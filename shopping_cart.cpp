#include <iostream>
#include <iomanip>

using namespace std;

class Cart
{
public:
  string Name;
  int Price;
  int Amt;
  int stock;
};

class ShoppingCart
{
private:
  Cart Products[100];

public:
  int cost = 0, Amt;
  void Add()
  {
    int n;
    cout << endl;
    cout << "enter no. of products you want to enter: ";
    cin >> n;
    if (n <= 100)
    {
      for (int i = 0; i < n; i++)
      {
        string Name;
        int Price;
        cout << "enter name: ";
        cin >> Products[i].Name;
        cout << "enter price: ";
        cin >> Products[i].Price;
        cout << "enter amount: ";
        cin >> Products[i].Amt;
        cost = cost + (Products[i].Price * Products[i].Amt);
        cout << "product added to cart" << endl;
      }
    }
    else
    {
      cout << "cart is full" << endl;
    }
  }

  void Display()
  {
    cout << "CART" << endl;
    for (int i = 0; i < 100; i++)
    {
      if (!Products[i].Name.empty())
      { // check if list is not empty
        cout << "product name: " << Products[i].Name << endl;
        cout << "price: " << Products[i].Price << endl;
      }
    }
    cout << "total cost: " << cost << endl;
  }

  void Remove(string ProdName)
  {
    int n = 100;
    for (int i = 0; i < n; i++)
    {
      if (Products[i].Name == ProdName)
      {
        cost = cost - (Products[i].Price * Products[i].Amt);
        for (int j = i; j < n - 1; j++)
        {
          Products[j] = Products[j + 1];
        }
        n--;
        cout << "product is removed from the cart" << endl;
        return;
      }
    }
    cout << "product not found\n"
         << endl;
  }
};

int main()
{
  ShoppingCart S1;
  string ProdName;
  while (true)
  {
    int choice;
    cout << endl;
    cout << "MENU" << endl;
    cout << endl;
    cout << " 1. add " << setw(10) << " 2. display " << setw(10) << " 3. remove " << setw(10) << " 4. exit" << endl;
    cout << endl;
    cout << "enter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      S1.Add();
      break;

    case 2:
      S1.Display();
      break;

    case 3:
      cout << "enter product name to delete: ";
      cin >> ProdName;
      // if (isupper(ProdName) || islower(ProdName)) {
      //   S1.Remove(ProdName);
      // }
      cout << "invalid name" << endl;
      break;

    case 4:
      exit(1);
      break;

    default:
      cout << endl;
      cout << "invalid input. try again" << endl;
    }
  }
}
