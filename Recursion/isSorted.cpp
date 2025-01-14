#include<iostream>
using namespace std;

bool isSorted(int *arr,int size)
{
    //base case
    if(size == 0 || size == 1)
    {
        return true;
    }
    else if(arr[0]>arr[1]) {
        return false;
    }
    else{
        bool remainingPart = isSorted(arr + 1,size - 1);
        return remainingPart;
    }
}

int main()
{
    int arr[5] = {1,3,2,7,6};
    int size = 5;

    int ans = isSorted(arr,size);
    if(ans)
    {
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Unsorted"<<endl;
    }
}