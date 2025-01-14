#include<iostream>
using namespace std;

void print(int *arr,int s,int e)  
{
    cout<<"Size of array is "<<(e - s + 1)<<endl;

    for(int i = s;i<=e;i++)
    {
        cout<<*(arr+i)<<" ";
    }cout<<endl;
}

bool binarySearch(int arr[],int start,int end,int key)
{
    print(arr,start,end);
    //base case
    if(start>end)
    {
        return false;
    }
    
    int mid = start + (end - start)/2;

    if(arr[mid] == key)
    {
        return true;
    }
    else if(arr[mid]<key)
    {
        binarySearch(arr,mid + 1,end,key);
    }
    else
    {
        binarySearch(arr,start,mid - 1,key);
    }

   
}

int main()
{
    int arr[6] = {2,4,6,14,18,32};
    int size = 6;                     //time complexity is O(log n)
    int key = 4;
    int start = 0;
    int end = size - 1;

    bool ans = binarySearch(arr,start,end,key);

    if(ans)
    {
        cout<<"Present"<<endl;
    }
    else
         cout<<"Absent"<<endl;
}