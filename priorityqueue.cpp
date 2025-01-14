#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> maxi;

    priority_queue<int,vector<int>,greater<int>> mini;

   
    maxi.push(0);
      maxi.push(3);
        maxi.push(1);
          maxi.push(2);
           int size2=maxi.size();
          for(int i = 0;i<size2;i++)
          {
            cout<<maxi.top()<<" ";
            maxi.pop();
          }

            mini.push(231);
      mini.push(3);
        mini.push(10);
          mini.push(2);
            int size=mini.size();
            for(int i = 0;i<size;i++)
          {
            cout<<mini.top()<<" ";
            mini.pop();
          }
     cout<<"Empty or not->"<<maxi.empty()<<endl;
}