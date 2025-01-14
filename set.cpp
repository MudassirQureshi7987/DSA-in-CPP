#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(6);
    s.insert(5);
      s.insert(5);
    s.insert(8);
     s.insert(6);
      s.insert(6);

      for(auto i:s)
      {
        cout<<i<<endl;
      }cout<<endl;

      set<int>::iterator it =s.end();
      it--;
      it--;

      set<int> :: iterator itr = s.find(5);
       for(auto ir=itr;ir!=s.end();ir++)
       {
         cout<<*ir<<" ";
       }
      

      s.erase(it);

      for(auto i:s)
      {
        cout<<endl<<i<<endl;
      }cout<<endl;
      
      cout<<"5 is present or not->"<<s.count(5)<<endl;


      
}