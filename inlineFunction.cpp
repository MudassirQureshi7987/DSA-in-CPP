#include<iostream>
using namespace std;

inline int func(int a,int b)        //compiler only accepts inline function if function body  is only 1 line
{                                   //if it is 2 or 3 lines then it depends on compiler
    return (a > b) ? a : b;         // if it is more than 3 lines than it doesn't accept at all
}

int main()
{
    int a = 3;
    int b = 5;
    
    int ans = func(a,b);

    a = a + 1;
    b = b - 3;

    ans = func(a,b);
}