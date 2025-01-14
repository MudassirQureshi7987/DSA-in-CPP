#include<iostream>
using namespace std;

int add(int a,int b)
{
    int c;
    c=a+b;
    return c;
}

class Employee{
       public:
         string name;
         int salary;

         Employee(string name,int salary,int sp)
         {
            this->name=name;
            this->salary=salary;
            this->secretpass=sp;
         }
         
         void printDetails()
         {
             cout<<"name "<<this->name<<" salary :"<<this->salary<<endl;
    
         }

           void getsecretpass()
           {
            cout<<"The secret pass is:"<<this->secretpass;
           }

            private:
            int secretpass;
     };

     class Programmer : public Employee
     {
        public:
           int errors;
     };
     
int main(){
    // cout<<"Hello World";
    // cout<<"Hello World"<<endl;
    // cout<<"mmm";

    // int a,b,c;
    // short sa=9;
    // cout<<sa;

    // camelCase Notation
    //    int marksInMaths=99;
    //    cout<<marksInMaths;

   /*int m=3;
    m=6;
    cout<<m;*/

   /* int const n=7;
    n=8;
    cout<<n;*/    
    // this will give an error cause const restrict changes
    // int a,b;
    // cout<<"Enter first number"<<endl;
    // cin>>a;

    // cout<<"Enter second number"<<endl;
    //  cin>>b;

    // cout<<"The sum is "<<a+b<<endl;
    // cout<<"The sum is "<<a+b<<endl;

  /*  int age;
    cout<<"Enter age:";
    cin>>age;

    if(age>100)
    {
        cout<<"Invalid";
    }
    else if(age>=18)
    {
        cout<<"You can vote";
    }
    else
    {
        cout<<"You cannot vote";
    }*/
// int a,b;

    //  cout<<"Enter first number"<<endl;
    //  cin>>a;

    //  cout<<"Enter second number"<<endl;
    //   cin>>b;

    // cout<<"The sum is "<<add(a,b)<<endl;

    // int arr[3]={1,2,3};
    // cout<<arr[1];

// int arr2d[2][3]={
    // {1,2,3},
    // {4,5,6}
// };
// for ( int i = 0; i < 2; i++)
// {
    // for (int j = 0; j < 3 ; j++)
    // {
        // cout<<"The value at"<<i<<","<<j<<"is "<<arr2d[i][j]<<endl;
    // }
// }

// int a=343;
// float b=87.67;
// cout<<(float) a/34<<endl;
// cout<<(int) b;

//    string name="Mudassir";
//    cout<<name<<endl;
//    cout<<name.length()<<endl;
//    cout<<name.substr(0,3)<<endl;
//    cout<<name.substr(3,4)<<endl;

    // int a=76;
    // int* ptra;
    // ptra=&a;
    // cout<<a<<endl;
    // cout<<*ptra<<endl;
    // cout<<&a<<endl;
    // cout<<ptra<<endl;
     
    //   Employee mm;
    //   mm.name="Mudassir";
    //   mm.salary=3444;
    //   mm.printDetails();
      Employee hm("hashir",655,76767);
      hm.printDetails();
      hm.getsecretpass();
    
     return 0;
}