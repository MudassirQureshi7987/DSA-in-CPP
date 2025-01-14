#include<iostream>
using namespace std;

int main()
{
    int a,b=1;
    a=10;
    if(++a)
    {
        cout<<b;
    }
    else
        cout<< ++b;

        int c=1;
        int d=c++;
        int e=++c;
        cout<< d;
        cout<< e;
}