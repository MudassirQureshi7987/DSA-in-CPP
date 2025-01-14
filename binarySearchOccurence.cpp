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

int firstOccurence(int arr[],int size,int key)
{

    int start=0;
    int end=size-1;
    // int mid= (start+end)/2;
    int mid = start + (end - start)/2;
    int ans;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
           
            end=mid-1;
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
   
    return ans;
}

int lastOccurence(int arr[],int size,int key)
{

    int start=0;
    int end=size-1;
    // int mid= (start+end)/2;
    int mid = start + (end - start)/2;
    int ans;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
           
            start=mid+1;
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
   
    return ans;
}

pair<int,int> bothOccurence(int arr[],int size,int key)
{
    pair<int,int> p;
   p.first=firstOccurence(arr,size,key);
   p.second=lastOccurence(arr,size,key);
   return p;
}



int main()
{
    
      int arr[10];
    inputArray(arr,7);
    int ans=firstOccurence(arr,7,11);
    int ans2=lastOccurence(arr,7,11);
    cout<<ans<<" "<<ans2;
 
}