// An inheritance which uses more than 1 type of inheritance

#include<iostream>
using namespace std;

class A
{
  public:
   void fun1()
   {
    cout<<"A"<<endl;
   }
};

class B
{
    public:
    void fun2()
    {
        cout<<"B"<<endl;
    }
};

class C : public A,public B{
    public:
    void fun3()
    {
        cout<<"C"<<endl;
    }
};

class D : public C
{
    public:
    void fun4()
    {
        cout<<"D"<<endl;
    }
};

class E : public C{
    public:
    void fun6()
    {
        cout<<"E"<<endl;
    }

};


int main()
{
  //multiple inheritance show
  
  cout<<"Multiple"<<endl;

  C mul;
  mul.fun1();
  mul.fun2();
  mul.fun3();

   cout<<endl<<endl;

  //hierarchical inheritance show
  
  cout<<"Hierarchical"<<endl;

  D a;
  a.fun3();

  E b;
  b.fun3();
}