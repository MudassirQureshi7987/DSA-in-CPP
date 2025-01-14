#include<iostream>
using namespace std;

void inputArray(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        cin>>arr[i];
    }
}

void sort01(int arr[],int size)
{
    int i=0,j=size-1;
    while(i<j) {
     if(arr[i]==0)
     {
        i++;
     }
     else if(arr[j]==1)
     {
        j--;
     }
     else
     {
        swap(arr[i],arr[j]);
        i++;
        j--;
     }
   }
}
   




void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}


int main()
{
   int arr[100];
   inputArray(arr,8);
   sort01(arr,8);
   cout<<endl;
   printArray(arr,8);
    
   

}