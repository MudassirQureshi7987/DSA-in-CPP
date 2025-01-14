#include<iostream>
using namespace std;

int pow(int base,int power)
{
    if(power==0)
     return 1;

    return base * pow(base,power - 1); 
}

int main()
{
    int base;
    int power;
    cin>>base>>power;

    int ans = pow(base,power);
    cout<<ans<<endl;
}