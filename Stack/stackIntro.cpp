#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(2);
    s.push(3);

    s.pop();

    cout<<"Element at top is "<< s.top() <<endl;
    s.emplace(3); //deep context but works like push almost 100%
    cout<<"Element at top is "<< s.top() <<endl;

    s.pop();

    if(s.empty())
    {
      cout<<"Stack is  empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    cout<<"Size ->"<<s.size()<<endl;
}