#include<iostream>
using namespace std;

#define MAX(a,b) (( a > b) ? a : b)
#define ARITHMETIC PI
#define PI 3.14


int main()
{
    int x=6;
    int y=5;

    cout<<"The maximum number is "<<MAX(x,y)<<endl;

    cout<<"The area of the circle is "<< (ARITHMETIC*12*12)<<endl;
}