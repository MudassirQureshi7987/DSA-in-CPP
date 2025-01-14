#include<iostream>
#include<string>
#include<vector>
using namespace std;

void reverseWords(string &s,int st,int e)
{
  while(st<=e)
  {
    swap(s[st++],s[e--]);
  }
}


int main()
{
    string s;
    getline(cin,s);
    
    int x=0;
    int y=0;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == ' ')
        {
          y=i-1;
          reverseWords(s,x,y);
          x=y+2;
            
        }
        if(s[i]=='\0')
        {
            y=s.length()-1;
            reverseWords(s,x,y);
        }
    }

    cout<<"After reverse"<<endl;
    cout<<s;
   
   return 0;
}