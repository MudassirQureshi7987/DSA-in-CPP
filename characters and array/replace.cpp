#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string s;
    getline(cin,s);

    for(int i = 0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            s.replace(i,1,"@40");
        }
    }
    cout<<s<<endl;

}