#include<iostream>
using namespace std;

bool isPossible(int *arr,int k,int n,int mid)
{
    int kCount=1;
    int countSum = 0;

    for(int i = 0;i<n;i++)
    {
        if(arr[i]+countSum<=mid)
        {
            countSum += arr[i];
        }
        else{
            kCount++;
            if(kCount>k || arr[i]>mid)
            {
                return false;
            }
            countSum = arr[i];
        }
    }
    return true;
}

void solve(int *arr,int k,int n,int s,int e,int& ans)
{
  //base case
  if(s>e)
  {
    return ;
  }
int mid = s + (e - s)/2;
  if(isPossible(arr,k,n,mid))
  {
    ans = mid;
    solve(arr,k,n,s,mid-1,ans);
  }
  else
  {
    solve(arr,k,n,mid+1,e,ans);
  }
}

int main()
{
    int arr[6] = {2, 1, 5, 6, 2, 3};
    int k = 2;
    int n = 6;

    int sum = 0;
    for(int i = 0;i<n;i++)
    {
      sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    solve(arr,k,n,0,e,ans);
    cout<<ans<<endl;
}