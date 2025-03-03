#include<iostream>
#include<queue>
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
        while(2*i <= size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;
            
            if(leftIndex <= size && arr[leftIndex] > arr[largest])
                largest = leftIndex;
            if(rightIndex <= size && arr[rightIndex] > arr[largest])
                largest = rightIndex;
            
            if(largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
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
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n)
{
    int size = n;

    while(size > 1)
    {
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
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




    cout<<"Using Priority Queue as MaxHeap"<<endl;

    priority_queue<int> pq;

    pq.push(4);
    pq.push(3);
    pq.push(6);
    pq.push(2);

    cout<<"Element at top is "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top is "<<pq.top()<<endl;
    cout<<"Size of priority queue is "<<pq.size()<<endl;
    if(pq.empty())
    {
        cout<<"Empty"<<endl
        ;
    }
    else
    {
        cout<<"Not Empty"<<endl;
    }
    
    //min Heap
    priority_queue<int,vector<int>,greater<int> > minHeap;

    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(6);
    minHeap.push(2);

    cout<<"Element at top is "<<minHeap.top()<<endl;

    return  0;
}