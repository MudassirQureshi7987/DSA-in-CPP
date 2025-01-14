#include<iostream>
using namespace std;

void insertionSort(int *arr,int s,int e)
{
    //base case
    if(s>e)
    {
        return ;
    }

    //processing edhe chale
    int   temp = arr[s];
    int i=s-1;
    while(arr[i]>temp && i>=0)
    {
        arr[i+1] = arr[i];
        i--;
     
    }
     arr[i+1] = temp;
     
    //R C
    insertionSort(arr,s+1,e);
}

int main()
{
    int arr[9] = {29,72,98,13,87,66,52,51,36};
    int size = 9;

    insertionSort(arr,1,size-1);

    for(int i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
}