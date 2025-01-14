#include<iostream>
using namespace std;

int getSum(int *arr,int size)
{
    int sum = 0;
    for(int i = 0;i<size;i++)
    {
        sum += *(arr + i);

    }
    return sum;
}

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i = 0;i<n;i++)
    {
      cin>>*(arr + i);
    }

    int ans = getSum(arr,n);
    cout<<"The sum is "<<ans<<endl;
}