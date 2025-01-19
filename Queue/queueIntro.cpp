#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(2);
    q.push(4);
    q.push(6);

    q.pop();

    cout<<"Size is "<< q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl;
    }

    cout<<"Front element is "<< q.front()<<endl;
    cout<<"Rare element is "<< q.back() <<endl;
}