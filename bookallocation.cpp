#include<iostream>
using namespace std;

bool isPossible(int *arr,int size,int m,int mid)
{
    int pageSum = 0;
    int studentCount = 1;
    int i = 0;

    while(i<size)
    {
        if(pageSum + arr[i] <= mid)
        {
            pageSum += arr[i++];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid)
            {
                return false;
            }
            pageSum = 0;
            i++;
        }
    }
    return true;
}

int bookAllocation(int *arr,int size,int m,int s,int e,int& ans)
{
    //base case
    if(s>e)
    {
        return ans;
    }

    int mid = s + (e - s)/2;

    if(isPossible(arr,size,m,mid))
    {
        ans = mid;
        bookAllocation(arr,size,m,s,mid-1,ans);
    }
    else{
        bookAllocation(arr,size,m,mid+1,e,ans);
    }



}

int main()
{
    int arr[4] = {12,34,67,90};
    int size = 4;
    int sum = 0;
    for(int i = 0;i<size;i++)
    {
        sum += arr[i];
    }
    int e = sum;

    int ans = -1;
    
   

    bookAllocation(arr,size,2,0,e,ans);

    cout<<ans<<endl;


}