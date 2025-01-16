#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int s,int mid,int e)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for(int i = 0;i<n1;i++)
    {
        left[i] = arr[s+i];
    }
    for(int i = 0;i<n2;i++)
    {
        right[i] = arr[mid+i+1];
    }

    //merge
    int i = 0,j = 0;
    int k = s;

    while( i < n1 && j < n2)
    {
        if(left[i]<=right[j])
        {
          arr[k] = left[i];
          i++;
                  
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr,int s,int e)
{
    //base case
    if(s>=e)
    {

       
        return ;
    }
   

    int mid = s + (e - s)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}