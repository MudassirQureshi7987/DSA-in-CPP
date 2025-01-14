#include<iostream>
#include<math.h>
#include<climits>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<5;i++)
    { 
        cout<<arr[i]<<endl;
    }
}

void inputArray(int arr[],int size)
{
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
}

void max(int arr[],int size)
  {
    int max = INT_MIN;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }

    }
    cout<<max<<endl;
  }

   void min(int arr[],int size)
  {
    int min = INT_MAX;

    for(int i=0;i<size;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }

    }
    cout<<min<<endl;
  }

int main()
{
    int array[100];
    inputArray(array, 5);
    max(array,5);
    min(array,5);
   
}