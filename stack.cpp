#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("Love");
    s.push("Babbar");
    
    cout<<s.top();
    s.pop();
    cout<<s.size();
}