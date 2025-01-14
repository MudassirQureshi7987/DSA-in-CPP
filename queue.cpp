#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<string> q;

    q.push("Muddu");
    q.push("Maddy");

    cout<<q.front();
    cout<<q.back();

    q.pop();
    cout<<q.front();
}