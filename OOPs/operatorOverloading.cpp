#include<iostream>
using namespace std;

class B
{
    public:
    int a;
    int b;

    void operator+ (B &obj)
    {
       int value1 = this->a;
       int value2 = obj.a;
       cout<<value2-value1<<endl;
    }

    void operator() ()
    {
        cout<<"bracket it is "<<this->a<<endl;
    }

    void operator= (B &obj)
    {

    }
};

int main()
{
  B obj1,obj2;

  obj1.a=4;
  obj2.a=8;
  obj1 + obj2;
  obj1();
  

}