#include<iostream>
#include<string>
#include<vector>
using namespace std;

char maxOccurenceCharacter(string &s)
{
    int arr[26]={0};
    for(int i = 0;i<s.length();i++)
    {
        char ch = s[i];
        int number = 0;
        if(ch>='a' && ch<='z')
        {
         number = ch - 'a';
        }
        else if(ch>='A'  && ch<='Z')
        {
            number = ch - 'A';
        }
        arr[number]++;  

        int maxi=-1;
        int ans = 0;

        for(int i = 0;i<26;i++)
        {
           if(maxi < arr[i])
           {
            ans = i;
            maxi = arr[i];
           }

         
        }
           char finalAns = 'a'+ans;
           return finalAns;
       

    }
}

int main()
{
    string s;
    cin>>s;
    char ans = maxOccurenceCharacter(s);
    cout<<endl;
    cout<<ans<<endl;

}