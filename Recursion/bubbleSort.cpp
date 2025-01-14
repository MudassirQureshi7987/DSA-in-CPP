#include<iostream>
using namespace std;

void bubbleSort(int *arr,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    //base case
    if(n==1)
     return ;

    for(int i = 0;i < n - 1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }

    }
    return bubbleSort(arr,n-1);
}

int main()
{
    cout<<"Enter the number of elements:";
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    bubbleSort(arr,n);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    delete []arr;
}