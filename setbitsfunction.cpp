#include<iostream>
using namespace std;

int bitcount(int n)
{
    int count=0;
    while(n!=0)
    {
        if(n & 1)
        {
          count++;
        }
        n=n>>1;
    }
    return count;
}

void setbits()
{
    int a,b;
    cin>>a>>b;
     
    int bitA=bitcount(a);
    int bitB=bitcount(b);

    bitA+=bitB;

     cout<<bitA;

}

int main()
{
  setbits();
}