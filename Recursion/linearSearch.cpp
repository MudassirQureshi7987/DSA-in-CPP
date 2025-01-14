#include<iostream>
using namespace std;

void print(int *arr,int size)
{
    cout<<"Size of array is "<<size<<endl;

    for(int i = 0;i<size;i++)
    {
        cout<<*(arr+i)<<" ";
    }cout<<endl;
}

bool search(int *arr,int size,int key)
{
    print(arr,size);
    //base case
    if(size == 0)
    {
        return false;
    }

    if(arr[0] == key)
    {
        return true;
    }
    else
        search(arr + 1,size-1,key);
}

int main()
{
    int arr[5] = {3,2,5,8,9};
    int size = 5;
    int key =  5;

    bool ans = search(arr,size,key);

    if(ans)
    {
        cout<<"Present"<<endl;
    }
    else 
        cout<<"Absent"<<endl;
}
