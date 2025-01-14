#include<iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    if(nStairs<0)
    {
        return 0;
    }
   if(nStairs==1)
   {
       return 1;
   }
   if(nStairs==2)
   {
       return 2;
   }
    
    int ans = countDistinctWays(nStairs-1)+ countDistinctWays(nStairs-2);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int ans = countDistinctWays(n);
    cout<<ans;


}


/*  
 int ans = countDistinctWays(nStairs-1)+ countDistinctWays(nStairs-2);
  countDistinctWays(nStairs-1)
5->4->3->2    2-2->3

            5(8)

  (3+2=5)4     3(2+!=3)

(2+1=3)3  (2)2 (2)2  (1)1   
     
(2)2    (1)1     



*/