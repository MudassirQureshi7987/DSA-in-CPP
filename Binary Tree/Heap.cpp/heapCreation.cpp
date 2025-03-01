#include<iostream>
using namespace std;

class heap
{
    public:
        int arr[100];
        int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;

            if(arr[index] > arr[parent])
            {
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else
            {
                return ;
            }
        }
    }

    void print()
    {
        for(int i = 1;i <= size;i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap()
    {
        // put last node to first node
        arr[1] = arr[size];

        //delete last node
        size--;

        //root node ko sahi position pe laa lo
        int i = 1;
        while(i < size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[leftIndex] > arr[i])
            {
                swap(arr[leftIndex],arr[i]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap(arr[rightIndex],arr[i]);
                i = rightIndex;
            }
            else
            {
                return ;
            }
        }
    }
};

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    else if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();
    int arr[] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i = n/2;i > 0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i = 1;i <= n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return  0;
}