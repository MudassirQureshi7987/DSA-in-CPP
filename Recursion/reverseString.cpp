#include<iostream>
using namespace std;

void reverse(string& str,int i,int size)
{
    //base case
    if(i>size-i-1)
    {
        return ;
    }

    swap(str[i],str[size-i-1]);
    i++;
    
    //R C
    reverse(str,i,size);
}
int main()
{
    string str = "abcdef";
    int size = str.length();

    reverse(str,0,size);

    cout<<str<<endl;
}