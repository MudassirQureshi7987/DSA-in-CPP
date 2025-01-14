#include<iostream>
using namespace std;

int main()
{
     int num = 5;
     int *ptr = &num;

   /*  cout<<"The value at num is "<<num<<endl;
     cout<<"The address of num is "<<ptr<<endl;
     cout<<"The value at num is "<<*ptr<<endl;
     
     char ch = 'a';
     char *pch = &ch;
     cout<<"The value at ch is "<<ch<<endl;
     cout<<"The address of  ch  is "<<pch<<endl;
     cout<<"The value at ch is "<<*pch<<endl;
     cout<<"Size of int num and char ch is "<<sizeof(num)<<" and "<<sizeof(ch)<<endl;
     cout<<"Size of int pointer ptr is "<<sizeof(ptr)<<endl;
     cout<<"Size of char pointer pch is "<<sizeof(pch)<<endl; */
     
      cout<<"The value at num is "<<num++<<endl;
      cout<<"The value at num is "<<(*ptr)++<<endl;
       cout<<"The value at num is "<<num++<<endl;
}