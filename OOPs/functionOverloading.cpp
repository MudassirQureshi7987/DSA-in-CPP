#include<iostream>
using namespace std;

class A
{
  public:
  int name;
  void fun()
  {
    cout<<"First"<<endl;
  }

  void fun(int name)
  {
    cout<<"second"<<endl;
    this->name = name;
  }

  int fun(int pain,char hen)
  {
    cout<<"Third"<<endl;
  }
};

int main()
{
  //we cannot overload function with just different return type
  //atleast we have to change the arguments or parameters given
  A a;
  a.fun();
  a.fun(2);
  a.fun(2,'a');

}