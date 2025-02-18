#include<iostream>
using namespace std;

class kQueue
{
    public:
        int freeSpot;
        int *arr;
        int *next;
        int *front;
        int *rear;
        int k;
        int n;


    kQueue(int k,int n)
    {
        this->k = k;
        this->n = n;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freeSpot = 0;

        for(int i = 0;i < k;i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i = 0;i < n;i++)
        {
            next[i] = i + 1;
        }
        next[n-1] = -1;
    }

    void enqueue(int data,int qn)
    {
        //overflow check
        if(freeSpot == -1)
        {
            cout<<"Overflow hai re bhai"<<endl;
            return ;
        }

        int index = freeSpot;

        freeSpot = next[index];

        //first element
        if(front[qn-1] == -1)
        {
            front[qn-1] = index;
        }
        else{ //link kardiye rear se isko
            next[rear[qn-1]] = index;
        }

        arr[index] = data;

        next[index] = -1;

        rear[qn-1] = index;
    }

    int dequeue(int qn)
    {
        //underflow check
        if(front[qn-1] == -1)
        {
            cout<<"Khali hai bey"<<endl;
            return -1;
        }

        int index = front[qn-1];

        front[qn-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};

int main() {

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}