#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}


void merge(int arr1[],int n,int arr2[],int m,int arr3[])
{
   int i=0;
   int j=0;
   int count=0;

   while(i<n && j<m)
   {
    if(arr1[i]<arr2[j])
    {
        arr3[count++]=arr1[i++];
       
    }
    else 
    {
        arr3[count++]=arr2[j++];
      
    }
  
   }
   cout<<"Print"<<endl;
   printArray(arr3,8);
   cout<<endl;
   while(i<n)
   {
    arr3[count++]=arr1[i++];
  
   }
   while(j<m)
   {
    arr3[count++]=arr2[j++];
   
   }
}



int main()
{
   int arr1[5]={1,3,6,9,22};
   int arr2[3]={2,7,13};

   int arr3[8]={0};

   merge(arr1,5,arr2,3,arr3);

   printArray(arr3,8);






    return 0;
}