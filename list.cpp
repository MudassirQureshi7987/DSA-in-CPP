#include<iostream>
#include<list>
using namespace std;

int main()
{
  list<int> l;
  l.push_back(2);
  l.push_front(1);
 
  for(int i:l)
  {
    cout<<i<<" ";
  }cout<<endl;
  list<int> p(5,123);
  cout<<"Size before->"<<p.size()<<endl;
p.push_back(1);
  p.push_front(2);
   cout<<"Size after->"<<p.size()<<endl;
  for(int i:p)
  {
    cout<<i<<" ";
  }
}