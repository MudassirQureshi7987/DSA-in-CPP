#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
   int n = arr.size();

   for(int i = 0;i<n-1;i++)
   {
      bool swape = false;

      for(int j = 0;j < n - i;j++)
      {
        if(arr[j] > arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            swape  = true;
        }
      }
      if(swape == false)
      {
        cout<<"Pass ->"<< i+1 <<endl;
        break;
      }
   }
}

void printArray(vector<int> arr)
{
    int n = arr.size();
    
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

}

int main()
{
    vector<int> arr = {1,5,4,3,2};

    cout << "Original array: ";
    printArray(arr); 

    bubbleSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}