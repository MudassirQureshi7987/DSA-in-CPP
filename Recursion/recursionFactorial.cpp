#include<iostream>
using namespace std;

int factorial(int n)
{
 /* if(n==0)                                   tail recursion              head recursion
  {                                            {                           {
                                                 base case                   base case
    return 1;                                    processing                  recursion relation
  }                                              recursive relation          processing
  int smallerProblem = factorial(n-1);          }                           }
  int biggerProblem = n * smallerProblem;

  return biggerProblem;  */

  if(n==0)        //base case/condition
   return 1;

   return n * factorial(n - 1);   //recursive relation
  }

int main()
{
    int n;               //time complexity is O(n)
    cin>>n;

    int ans = factorial(n);
    cout<<ans<<endl;
}