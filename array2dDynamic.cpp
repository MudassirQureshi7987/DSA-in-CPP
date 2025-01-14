#include<iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"Enter the value of rows and columns:";
    cin>>row;
    cin>>col;

    int** arr = new int*[row];
    for(int i = 0; i<row ;i++)
    {
        arr[i] = new int[col];
    }

    for(int i = 0;i<row;i++)
    {
        for(int j = 0;i<col;j++)
        {
           cin>>arr[i][j];
        }  
    }

     for(int i = 0;i<row;i++)
    {
        for(int j = 0;i<col;j++)
        {
          cout<<arr[i][j]<<" ";
        }  cout<<endl;
    }
    return 0;
}