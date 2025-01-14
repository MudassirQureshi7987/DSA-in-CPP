#include<iostream>
using namespace std;

int score = 23;    //BAD Practice
                   //instead use reference variable

void a(int i)
{
     score++;
    cout<< score <<" in a"<<endl;
}

void b(int i)
{
    cout<< score <<" in b"<<endl;
   
}

int main()
{
    cout<< score << " in main"<<endl;
    a(5);
    b(7);
}