#include<iostream>
using namespace std;

void print(int *p)
{
    p = p + 1;
    cout<<"Value is "<<*p<<endl;
    
}

int getSum(int arr[],int size)
{
    int sum = 0;
    for(int i = 0;i<size;i++)
    {
      sum += arr[i];
    }
  return sum;
}

int main()
{
   /* int arr[10] = {23,122,41,67};
   
    cout<<"Size of arr is "<<(*arr )<<endl;
    cout<<"The value at arr is "<<arr[0]<<endl;
    cout<<"Address of first memory block is "<<&arr[0]<<endl;

    cout<<"4th "<<*arr<<endl;
    cout<<"5th "<<*arr + 1<<endl;
    cout<<"6th "<<*(arr+1)<<endl;
    cout<<"7th "<<(*arr)+1<<endl;     

    int value = 5;
    int *p = &value;

    print(p);
    cout<<"In main "<<*p<<endl;   */

    int arr[5] = {12,32,11,54,26};

    int ans = getSum(arr+3,5);
    cout<<ans<<endl;







}