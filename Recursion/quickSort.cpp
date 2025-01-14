#include<iostream>
using namespace std;

int partition(int *arr,int s,int e)
{
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
          count++;
        }
    }

    //pivot ko right position pe layege
    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    int i = s,j = e;
    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] <= pivot)
        {
            i++;
        }

        while(arr[j] >= pivot)
        {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
    }

return pivotIndex;
}

void quickSort(int *arr,int s,int e)
{

   
    //base case
    if(s>=e)
    {
        return ;
    }

    //pivot nikal lege aur partition karege
    int pivot =  partition(arr,s,e);

    //left wala part sort karege pivot ke
    quickSort(arr,s,pivot-1);

    //right wala karege
    quickSort(arr,pivot+1,e);
}

int main()
{
    int arr[5] ={4,12,2,7,8};
    int n = 5;

    quickSort(arr,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }cout<<endl;
}