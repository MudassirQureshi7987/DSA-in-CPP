#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int s,int e)
{
   int pivot = arr[s];

   int count = 0;

   for(int i = s+1;i<e;i++)
   {
    if(arr[i]<=pivot)
    {
        count++;
    }
   }

   int pivotIndex = s + count;

   swap(arr[s],arr[pivotIndex]);

   int i = s,j = e;

   while( i<pivotIndex && j>pivotIndex)
   {
    while(arr[i]<=pivot)
    {
        i++;
    }

    while(arr[j]>pivot)
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

void quickSort(vector<int> &arr,int s,int e)
{
    
    //base case
    if(s>=e)
      return;

    int pivot = partition(arr,s,e);
    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot+1,e);
}

int main()
{
    vector<int> arr = {2,4,1,1,1,6,9,9,9};
    int n = arr.size();

    quickSort(arr,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}