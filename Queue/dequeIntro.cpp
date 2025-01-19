#include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int> d;

    d.push_front(2);
    d.push_back(3);

    cout<< d.front()<<endl;
    cout<< d.back()<<endl;

    d.pop_back();

    cout<< d.front()<<endl;
    cout<< d.back()<<endl;

    if(d.empty())
    {
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }


}