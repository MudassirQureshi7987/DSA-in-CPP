#include<iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        cout<<arr[i]<<endl;
    }
}

void inputArray(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        cin>>arr[i];
    }
}

void swapAlternate(int arr[],int size)
{
    int temp;
    temp=arr[size-1];
    
   for(int i=0;i<=size-1;i+=2)
   {
    int one=i;
   int two=one+1;
  

    swap(arr[one],arr[two]);
   }
   if(size %2==1)
   {
    arr[size-1]=temp;
   }
   
   
}

int main()
{
    int arr[5];
    int arr2[6];

   inputArray(arr,5);
    swapAlternate(arr,5);
    cout<<endl;
    printArray(arr,5);

     inputArray(arr2,6);
    swapAlternate(arr2,6);
    cout<<endl;
    printArray(arr2,6);

}