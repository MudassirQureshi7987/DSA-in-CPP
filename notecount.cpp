#include<iostream>
using namespace std;

int main()
  {
    int n;
    cout<<"Enter the amount:";
    cin>>n;
    int hund,fifty ,twenty ,one;

       switch(1)
       {
        case 1:hund=n/100;
               n=n%100;
               cout<<"100 Rupees note are "<<hund<<endl;
        case 2:fifty=n/50;
               n=n%50;
               cout<<"50 Rupees note are "<<fifty<<endl;

        case 3:twenty=n/20;
               n=n%20;
               cout<<"20 Rupees notes are "<<twenty<<endl;

        case 4:one=n/1;
               n=n%1;
               cout<<"1 Rupees note are "<<one;            

    
       }


  }