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

bool search(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return 1;
        }
        
    }
    return 0;
}


int main()
{
    int array[5];
    inputArray(array, 5);
    int ans=search(array,5,11);

    if(ans)
    {
        cout<<"Key is present";
    }
    else
    {
        cout<<"Key is not present";
    }
   
}