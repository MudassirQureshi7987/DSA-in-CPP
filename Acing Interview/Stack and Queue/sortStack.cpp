#include<iostream>
#include<stack>
using namespace std;

void sortStack(stack<int> &st1)
{
    stack<int> st2;

    while(!st1.empty())
    {
        int element = st1.top();
        st1.pop();

        if(st2.empty())
        {
            st2.push(element);
        }
        else
        {
            while(!st2.empty() && element < st2.top())
            {
                st1.push(st2.top());
               
                st2.pop();
            }
            st2.push(element);
        }

    }
}

int main()
{

}