#include<iostream>
using namespace std;

class Animal
{
    public:
    void speak()
    {
    cout<<"Animal speaks"<<endl;
    }
};

class Dog : public Animal
{
    public:
    void speak()
    {
        cout<<"Dog barks"<<endl;
    }
};

class Cat : public Dog{
    public:
    void speak()
    {
        cout<<"Kriti meow meow olelelelelelelele"<<endl;
    }

};

int main()
{
  Cat Kriti;
  Kriti.speak();
}