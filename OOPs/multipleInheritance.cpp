#include<iostream>
using namespace std;

class A
{
    public:
    int height;

    public:
    void a()
    {
        cout<<"A"<<endl;
    }
};

class B
{
    public:
    int name;

    public:
    void b()
    {
        cout<<"B"<<endl;
    }


};

class C : public A,public B
{
    public:
    void c()
    {
        cout<<"C"<<endl;
    }
};

int main()
{
  C object;
  object.a();
  object.b();
  object.c();
}