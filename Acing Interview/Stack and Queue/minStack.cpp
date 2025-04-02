#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

class MinStack {
    stack<long long int> s;
    long long int mini = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(s.empty())
        {
            s.push(val);
            mini = val;
        }
        else
        {
            if(val < mini)
            {
                s.push((long long)2*val - mini);
                mini = val;
            }
            else
            {
                s.push(val);
            }
        }
    }
    
    void pop() {
        
        if(s.top() < mini)
        {
            mini = 2*mini - s.top();
        }
        s.pop();
    }
    
    int top() {
        
        if(s.top() < mini)
        {
            return mini;
        }
        else
        {
            return s.top();
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 class MinStack {
    public:
        stack<int> s;
        stack<int> m;
        
    
        MinStack() {
            
        }
        
        void push(int val) {
           s.push(val);
           if(m.empty() || val < m.top())
           {
            m.push(val);
           }
           else
           {
            m.push(m.top());
           }
        }
        
        void pop() {
            s.pop();
            m.pop();
        }
        
        int top() {
            return s.top();
        }
        
        int getMin() {
            return m.top();
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */