#include<iostream>
using namespace std;

int main()
  {
    int n;
    cin>>n;
    int row=1;

    while(row<=n)
    {
   // print space

    int space=n-row;
    while(space)
    {
        cout<<" ";
        space=space-1;

    }
    // print 1st tri
    int col=1;
    while(col<=row)
    {
        cout<<col;
        col=col+1;
    }

    // print 2nd tri

    int start=row-1;
    while(start)
    {
      cout<<start;
      start=start-1;
    }
    cout<<endl;
    row=row+1;

    }
  }

      