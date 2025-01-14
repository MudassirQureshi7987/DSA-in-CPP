#include<iostream>
using namespace std;

/*
In multiple inheritance case,if the name of the data members of both 
the parent class collides then we have to use the name of parent class with :: that is 
scope operator I guess Idk

*/

class A
{
  public:
  void fun()
  {
    cout<<"A"<<endl;
  }
};

class B
{
    public:
    void fun()
    {
        cout<<"B"<<endl;
    }
};

class C : public A,public B
{

};

int main()
{
  C obj;
  obj.A::fun();
  obj.B::fun();
}