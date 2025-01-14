#include<iostream>
using namespace std;

int partition(int *arr,int s,int e)
{
   
  int pivot = arr[s];
  int count = 0;

  //pivot se bade elements right mai
  for(int i = s+1;i<=e;i++)
  {
    if(arr[i]<=pivot)
    {
        count++;
    }
  }

  //pivot ko right place pe rakhde
  int  pivotIndex = s + count;
  swap(arr[s],arr[pivotIndex]);

  //pivot ki right or left sides sahi karni h
  int i = s,j = e;

  while(i<pivotIndex && j>pivotIndex)
  {
    while(arr[i]<pivot)
    {
        i++;
    }

    while(arr[j]>
    pivot)
    {
        j--;
    }

    if(i<pivotIndex && j>pivotIndex)
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

    //pivot nikal lege
    int p = partition(arr,s,e);

    //left part sort karlege
    quickSort(arr,s,p-1);
    
    //right part ko kar
    quickSort(arr,p+1,e);

}


int main()
{
    int arr[5] = {4, 2, 1, 5, 3};
    int n = 5;

    quickSort(arr,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }cout<<endl;
}