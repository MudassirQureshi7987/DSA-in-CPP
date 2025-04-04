#include<stack>
#include<iostream>
using namepace std;

class Queue {
    // Define the data members(if any) here.
    stack<int> newValue;
    stack<int> reverse;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        newValue.push(val);
    }

    int deQueue() {
        if(isEmpty())
        {
            return -1;
        }
        // Implement the dequeue() function.
        if(reverse.empty())
        {
            while(!newValue.empty())
            {
                reverse.push(newValue.top());
                newValue.pop();
                
            }
            int element = reverse.top();
            reverse.pop();
            return element;
        }
        else
        {
            int element = reverse.top();
            reverse.pop();
            return element;
        }
            
    }

    int peek() {
        if(isEmpty())
        {
            return -1;
        }
        // Implement the dequeue() function.
        if(reverse.empty())
        {
            while(!newValue.empty())
            {
                reverse.push(newValue.top());
                newValue.pop();
                
            }
            int element = reverse.top();
          
            return element;
        }
        else
        {
            int element = reverse.top();
      
            return element;
        }
            
    }

    bool isEmpty() {
        if(newValue.empty() && reverse.empty())
        {
            return true;
        }
        return false;
    }
};