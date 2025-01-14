#include<iostream>
using namespace std;

bool isPresent(int arr[][3],int target,int row,int col)
{
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
          if(arr[i][j]==target)
          {
            return true;
          }
        }
    }
    return false;
}

void rowSum(int arr[][3],int row,int col)
{
     for(int i = 0;i<row;i++)
    {
        int sum = 0;
        for(int j = 0;j<col;j++)
        {
          sum += arr[i][j];
        }
        cout<<sum<<" ";
    }
    
}

int main()
{
    //int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
   // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
   int arr[3][3];
    //input row wise
    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col<3;col++)
        {
            cin>>arr[row][col];
        }
    }

   //input column wise
 /* for(int col = 0;col<4;col++){
     for(int row = 0;row<3;row++)
     {
       cin>>arr[row][col];
     }
  }*/
    

    //print
    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col<3;col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Element to be searched:";
    cin>>target;

    if(isPresent(arr,target,3,3))
    {
       cout<<"Element found";
    }
    else
    {
        cout<<"Element not found";
    }
    cout<<endl;

    cout<<"Sum of rows->";
    rowSum(arr,3,3);

}