#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    string str;
    cin >> str;

    for(int i = a;i < n - b;i++)
    {
        cout << str[i] ;
    }
}
