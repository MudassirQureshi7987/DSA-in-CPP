#include<iostream>
using namespace std;

int main()
  {
    int n;
    cin>>n;
    int row=1;

    while(row<=n)
      {
        int col;       
        int space=n-row;                         
         while(space)
         {
            cout<<" ";
            space=space-1;
          
         }
         
         col=1;
         while(col<=row)
         {
            cout<<"*";
            col=col+1;
         }
         cout<<endl;
           row=row+1;
      }
  }

      