#include <iostream>
#include <numeric>  // for std::gcd
using namespace std;

int gcdManual(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;

    while(a!=b)
    {
        if(a>b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main()
{
    int a,b;
    cout<<"Enter the numbers:";
    cin>>a>>b;

    int ans = gcdManual(a,b);
    cout<<"GCD (manual) of "<<a<<" and "<<b<<" is "<<ans;

    int ans2 = std::gcd(a,b);   // ✅ Corrected
    cout<<"\nGCD (using std::gcd) of "<<a<<" and "<<b<<" is "<<ans2;

    return 0;
}
