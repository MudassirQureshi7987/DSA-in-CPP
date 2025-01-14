#include<iostream>
using namespace std;

void inversionCount(int *arr,int n,int s,int& count)
{
  //base case
  if(s==n)
  {
    return ;
  }

  for(int i = s+1;i<=n;i++)
  {
    if(arr[s]>arr[i])
    {
        count++;
    }
  }
  inversionCount(arr,n,s+1,count);
}

int main()
{
    int arr[4] = {7,2,6,3};
    int n = 4;
    int count = 0;

    inversionCount(arr,n-1,0,count);

    cout<<"Inversion count is "<<count<<endl;
}