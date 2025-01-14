#include<iostream>
#include<array>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}

void inputArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}


int main()
{
   int basic[4]={1,2,3,4};
   for(int i:basic)
   {
    cout<<i<<" ";
   }

   array<int,5> a = {2,4,6,8,10};

   for(int i:a)
   {
    cout<<i<<" ";
   }

   cout<<endl<<a.at(2)<<endl;

   cout<<"Empty or not->"<<a.empty();
}