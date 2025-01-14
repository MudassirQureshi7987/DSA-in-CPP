#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d={1,2,3};

    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    d.push_back(4);
    d.push_front(0);
     for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    d.erase(d.begin(),d.begin()+1);
      for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size->"<<d.size();
    cout<<endl;
    d.erase(d.end(),d.end()+d.size());
    
 for(int i:d)
    {
        cout<<i<<" ";
    }

}