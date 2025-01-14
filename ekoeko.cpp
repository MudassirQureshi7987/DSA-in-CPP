#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int ekoeko(int arr[],int m,int mid)
{

}

int main()
{
 long long arr[]={20,10,15,17};
  int m = 7;
   int size = 4;
   int h;
   int mini=214748364;
   int maxi = -1;
   for(int i=0;i<size;i++ )
   {
      mini = min(mini,arr[i]);
      maxi = max(maxi,arr[i]);
      
   }
   int mid = mini + ( maxi - mini)/2;
   sort(arr.begin(),arr.end());
   
   while(mini<=maxi)
   {
    if(mid)
   }





}