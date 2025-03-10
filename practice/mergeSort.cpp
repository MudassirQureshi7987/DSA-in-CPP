#include<iostream>
using namespace std;

void merge(int *arr,int s,int e,int mid)
{
    if(s>=e)
    {
        return ;
    }

    int len1= mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int index=s;

    for(int i = 0;i<len1;i++)
    {
        first[i]=arr[index++];
    }

    for(int i = 0;i<len2;i++)
    {
        second[i]=arr[index++];
    }

    int index1=0;
    int index2=0;
    int mainArrayIndex=s;

    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else 
        {
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1<len1)
    {
        arr[mainArrayIndex++]=first[index1++];
    }

    while(index2<len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }

    delete []first;
    delete []second;


}

void mergeSort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
    {
        return ;
    }

    int mid = s + (e-s)/2;

    //left part sort
    mergeSort(arr,s,mid);

    //right part sort
    mergeSort(arr,mid+1,e);

    //merging both arrays
    merge(arr,s,e,mid);
}

int main()
{
    int arr[7] = {3,27,12,56,54,32,87};
    int n = 7;

    mergeSort(arr,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }cout<<endl;
}