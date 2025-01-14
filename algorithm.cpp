#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{

    vector<int> v;

   v.push_back(1);
      v.push_back(2);
       v.push_back(3);
    v.push_back(6);
    v.push_back(8);
 
    
    cout<<"Finding 6->"<<binary_search(v.begin(),v.end(),6)<<endl;

    cout<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    int a=3;
    int b=4;

    cout<<"Max->"<<max(a,b)<<endl;
     cout<<"Min->"<<min(a,b)<<endl;

     swap(a,b);

     cout<<"a->"<<a<<endl;

     string abcd="abcde";
     reverse(abcd.begin()+3,abcd.end());
     cout<<"String->"<<abcd<<endl;

     rotate(v.begin(),v.begin()+2,v.end());
     for(auto i:v)
     {
        cout<<i<<" ";
     }cout<<endl;
     sort(v.begin(),v.end());
      for(auto i:v)
     {
        cout<<i<<" ";
     }

}