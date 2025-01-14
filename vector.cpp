#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    vector<int> a(6,8);
    for(int i:a)
    {
        cout<<i<<" ";
    }
    vector<int> last(a);
    for(int i:last)
    {
        cout<<i<<" ";
    }
    cout<<"Capacity->"<<v.capacity()<<endl;

    v.push_back(1);
     cout<<"Capacity->"<<v.capacity()<<endl;

      v.push_back(2);
       cout<<"Capacity->"<<v.capacity()<<endl;

       v.push_back(3);
          cout<<"Capacity->"<<v.capacity()<<endl;

          cout<<"Size->"<<v.size()<<endl;

          cout<<"Element at 2nd index->"<<v.at(2)<<endl;
          cout<<"Element at 0th index->"<<v[0]<<endl;

          cout<<"Front ->"<<v.front()<<endl;
          cout<<"Back"<<v.back()<<endl;
          
          cout<<"Before pop"<<endl;
          for(int i:v)
          {
            cout<<i<<" ";
          }
          
          v.pop_back();
          cout<<endl<<"After pop"<<endl;
          for(int i:v)
          {
            cout<<i<<" ";
          }


          v.clear();
          cout<<"After clear v="<<v.size()<<endl;
          cout<<"After clear v="<<v.capacity()<<endl;
}



