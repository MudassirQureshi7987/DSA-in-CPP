#include<iostream>
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

void reverse(int arr[],int size)
{
   /* for(int i=0;i<(size/2);i++)
    {
        int temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
*/     
         int start=0;
         int end = size - 1;

         while(start<=end)
         {
            swap(arr[start],arr[end]);
            start++;
            end--;
         }


      
    }



int main()
{
    int array[5];
    int arr[6];
    inputArray(array, 5);
    reverse(array,5);
    printArray(array,5);
    inputArray(arr, 6);
    reverse(arr,6);
    printArray(arr,6);
    
   
}