#include<iostream>
using namespace std;

int main()
  {
    int num=2;
    char ch='1';

     switch(num)
     {
        case 1:cout <<num<<endl;

        case 2:switch(ch)
        {
            case '1':cout<<ch<<endl;
            break;

        }
        break;
        default:cout<<"This is default case";

     }
  }