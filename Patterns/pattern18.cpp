#include<iostream>
using namespace std;

int main()
  {
    int n;
    cin>>n;
    int row=1;
     
     while(row<=n)
      {
        int value=n-row+1;
         while(value)
         {
            cout<<row;
            value=value-1;
         }
         cout<<endl;
         row=row+1;
      }
  }

      