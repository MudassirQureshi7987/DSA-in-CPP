#include<iostream>
using namespace std;

class Complex 
{
  int real,img;

  public:

  Complex()
  {

  }
  Complex(int real,int img)
  {
    this->real = real;
    this->img = img;
  }

  void display()
  {
    cout<<real<<" "<<"+"<<" "<<"i"<<img<<endl;
  }

  Complex operator +(Complex &C)
  {
    Complex ans;
    ans.real = real + C.real;
    ans.img = img + C.img;
    return ans;
  }
};

int main()
{
   Complex obj1(3,4);
   Complex obj2(4,6);
   Complex obj3 = obj1 + obj2;

   obj3.display();





    return 0;
}