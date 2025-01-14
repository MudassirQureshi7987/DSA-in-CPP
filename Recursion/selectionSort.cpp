#include<iostream>
using namespace std;

void selectionSort(int *arr,int s,int e)
{
    //base case
    if(s>e)
    {
        return;
    }

    for(int i = s+1;i<=e;i++)
    {
        if(arr[s]>arr[i])
        {
            swap(arr[s],arr[i]);
        }
    }
    //R C
    selectionSort(arr,s+1,e);
}


int main()
{
    int arr[9] = {29,72,98,13,87,66,52,51,36};
    int size = 9;

    selectionSort(arr,0,size-1);

    for(int i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
}