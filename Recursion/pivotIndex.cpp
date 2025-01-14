#include<iostream>
using namespace std;

int pivotIndex(int arr[],int size,int s,int e,int leftSum)
{
   //base case
  if(s==size)
  {
    return -1;
  }

 
  if(s==0)
  {
    leftSum = 0;
  }
  else
  {
    leftSum = leftSum + arr[s-1];
  }
  int rightSum = 0;
  for(int i = s + 1;i<size;i++)
  {
    rightSum = rightSum + arr[i];
  }
   
   if(rightSum==leftSum)
   {
    return s;
   }
   else{
    pivotIndex(arr,size,s++,e,leftSum);
   }
}

int main()
{
    int arr[6] = {1,7,3,6,5,6};
    //pivotIndex = 3 here 
    //cause 1+7+3 = 5+6
    //The elements to the right and left of 3rd index gets the same sum so 3 is the pivot index here

    int size = 6;
    int leftSum = 0;
    int ans= pivotIndex(arr,size,0,size-1,leftSum);

  
       cout<<ans<<endl;
}