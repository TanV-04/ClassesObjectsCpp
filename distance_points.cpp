#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Points
{
public:
  int x1, x2, y1, y2;

  void Enter()
  {
    cout << "enter x1, x2: ";
    cin >> x1 >> x2;
    cout << "enter y1, y2: ";
    cin >> y1 >> y2;
  }
};

class Distance : public Points
{
public:
  void Calc()
  {
    Enter();
    float distance;
    distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    cout << "distance between the points is " << distance << " units";
  }
};

int main()
{
  Distance d1;
  d1.Calc();
}