#include<iostream>
using namespace std;

int main()
{
  /*  int num = 5;
    int *ptr = &num;
    int *p = ptr;

    cout<<"Value at pointer p is "<<(*p)++<<endl;
    cout<<num;    */

    int i = 3;
    int *t = &i;
    *t = *t + 1;
    cout<<i;
    cout<<"Before "<<endl;
    cout<<t<<endl;
    t = t + 1;
    cout<<"after"<<endl;
    cout<<t;
    t = t - 1;
    cout<<"After minus "<<endl;
    cout<<t;
}

