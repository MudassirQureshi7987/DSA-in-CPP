#include<iostream>
using namespace std;

void inputArray(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        cin>>arr[i];
    }
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}

void sort012(int arr[],int size)
{
    int i,j,k;

    i=0;
    j=0;
    k=size-1;
   while(j<=k){
    switch(arr[j])
    {
        case 0:swap(arr[i++],arr[j++]);
        break;

        case 1:j++;
        break;

        case 2:swap(arr[j],arr[k--]);
    }
   }
}

int main()
{
   int arr[100];
   inputArray(arr,8);
   sort012(arr,8);
   cout<<endl;
   printArray(arr,8);
    
   
}