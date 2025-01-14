#include<iostream>
#include<array>
using namespace std;

int partition(int *arr,int s,int e)
{
    int pivot = arr[s];
    int cnt = 0;

    for(int i = s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            cnt++;
        }
    }

    //putting the pivot at it's right positiom
    int pivotIndex = s + cnt;
    swap(arr[s],arr[pivotIndex]);

    //arrange the left and right part of the pivot accordingly

    int i = s;
    int j = e;

    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<pivot){
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if( i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i],arr[j]);
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
    
    //this will put pivot element on right place and also arrange left and right of it accordingly
    int pivot = partition(arr,s,e);

    //sorting the left part
    quickSort(arr,s,pivot-1);

    //sorting the right part
    quickSort(arr,pivot+1,e);
}

int main()
{
    int arr[1] = {4};
    int size = 1                                                                          ;
    
    quickSort(arr,0,size-1);

    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}