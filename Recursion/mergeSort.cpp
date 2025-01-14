#include<iostream>
using namespace std;

void merge(int *arr,int s,int e)
{
    int mid = s + (e - s)/2;
    //left part length
    int len1 = mid - s + 1;
    //right part length
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    
    //copy first array
    for(int i = 0;i<len1;i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    //copy second array
    for(int i = 0;i<len2;i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    //merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrayIndex++] = first[index1++]; 
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1<len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2<len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }



}

void mergeSort(int *arr,int s,int e)
{
    //base case
    if(s>=e)
    {
        return ;
    }

    int mid = s + (e - s)/2;

    //left part sort
    mergeSort(arr,s,mid);

    //right part sort
    mergeSort(arr,mid+1,e);

    //merging both arrays
    merge(arr,s,e);
}

int main()
{
    int arr[6] = {3,2,1,5,9,6};        //time complexity is O(n)
    int n = 6
    ;

    mergeSort(arr,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

}