#include<iostream>
#include<array>
using namespace std;

void printArray(int arr[])
{
    int size = sizeof(arr);

    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<endl;
        
    }
    cout<<endl;
}

void scanArray(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}

int main()
{
    int arr[5] = {1,3,5,7,9};
    printArray(arr);

    int aar[6];

    scanArray(aar,6);
    printArray(aar);

    return 0;

}