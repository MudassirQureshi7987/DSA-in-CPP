#include<iostream>
using namespace std;

void print(int arr[],int n,int start = 0)   //default argument can only be given to the rightmost and so on
{
    for(int i = start;i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[5] = {1,3,5,7,9};

    print(arr,5);
    cout<<endl;
    print(arr,4,2);
}

