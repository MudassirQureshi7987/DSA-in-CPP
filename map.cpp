#include<iostream>
#include<map>
using namespace std;
 
 int main()
 {
    map<int,string> map;

    map[1]="Love";
    map[2]="Babbar";
    map[12]="Baba";

    map.insert({5,"Close"});

    for(auto i:map)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    map.erase(5);
    for(auto i:map)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

   auto it = map.find(2);

   for(auto i = it;i!=map.end();i++)
   {
     cout<<(*i).first<<" "<<(*i).second<<endl;
   }
 }
