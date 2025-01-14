
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

int binarySearch(int arr[],int size,int key)
{

    int start=0;
    int end=size-1;
    // int mid= (start+end)/2;
    int mid = start + (end - start)/2;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            start=mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
         mid = start + (end - start)/2;

    }
    return -1;
}



int main()
{
    int arr[10];
    inputArray(arr,7);
    int ans=binarySearch(arr,7,11);
    cout<<"Index="<<ans;

    // Time complexity is O(log n)
}