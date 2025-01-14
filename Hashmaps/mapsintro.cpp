#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    //creation
    unordered_map<string,int> m;

    //insertion

    //1
    pair<string,int> pair1 = make_pair("babbar",3);
    m.insert(pair1);

    //2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    //3
    m["mera"] = 1;
    

    //search
    cout<< m["mera"] <<endl;
    
    cout<< m.at("love") <<endl;

    //if we search something that has no entry then m["unknown"] will create a new entry
    //but m.at["unknown"] will show terminate and out of range

    //cout<< m.at("unknown") <<endl;

    cout<< m["unknown"] <<endl;
    cout<< m.at("unknown") <<endl;

    //size
    cout<< m.size() <<endl;

    //to check presence
    cout<< m.count("bro") <<endl; // output would be 0 if absent and 1 if present
    cout<< m.count("love") <<endl;

    //delete
    m.erase("mera");
    cout<< m.size()<<endl;

    //when we iterate through an unordered map,it would print things randomly
    //but when we use map then they would get printed in the order of their entry
    
    //iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while( it != m.end())
    {
      cout<< it->first <<" "<< it->second <<endl;
      it++;
    }

    //iterate second way
    //in this way,we use . dot and in first we use -> arrow

    for(auto i:m)
    {
        cout<< i.first <<" "<<i.second<<endl;
    }

    //unordered map complexity === constant time
    //ordered map aka map complexity === log N

}