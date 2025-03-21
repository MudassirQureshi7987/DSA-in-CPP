#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }

    while(a!=b)
    {
        if(a>b)
        {
            a = a - b;
        }
        else if(b>a)
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    int a,b;
    cout<<"Enter the numbers:";
    cin>>a>>b;

    int ans = gcd(a,b);
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<ans;
}