#include<iostream>
using namespace std;

int main()
  {
    int n;
    cin>>n;
    int row=1;
     
     while(row<=n)
      {
        // print first triangle
        int fuck=1;
        int value=n-row+1;
         while(value)
         {
            cout<<fuck;
            value=value-1;
            fuck=fuck+1;
            
         }
         
        //  print 2nd triangle
         int col=2;
         int c1star=n-row;
         while(col<=row)
         {
          cout<<"**";
          col=col+1;
         }

        //  print 3rd triangle
        
        
          int fuck2=n;
         int value2=n-row+1;
         while(value2)
         {
            cout<<fuck2;
            value2=value2-1;
            fuck2=fuck2-1;
         }
         



         cout<<endl;
         row=row+1;
      }
  }

      
  