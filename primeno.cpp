#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int isPrime=1;

    for(int i=2;i<n;i++)
    {
        if(n % i==0)
        {
            // cout<<endl<<"n is not a prime number";
            isPrime=0;
            break;
        }
        
    }

    if(isPrime==0)
    {
        cout<<"Not a prime number";
    }
    else
            cout<<endl<<"n is a prime number";
            
}