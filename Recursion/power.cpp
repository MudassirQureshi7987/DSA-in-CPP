#include<iostream>
using namespace std;

int power(int x,int n)
{
  //base case
  if(n==0)
   return 1;

  if(n==1)
   return x;

  int ans = power(x,n/2);

  if(n&1)
  {
    return x*ans*ans;
  }
  else
     return ans*ans;

  

}

int main()
{
    int base;
    int n;
    cin>>base>>n;

    int ans = power(base,n);
    cout<<ans<<endl;
}