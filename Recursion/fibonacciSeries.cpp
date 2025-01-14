#include<iostream>
using namespace std;

int fibonacci(int n)
{
    //base case
    if(n==0 || n==1)
    {
        return n;
    }

    int sum = fibonacci(n-1) + fibonacci(n-2);

    return sum;


}

int main()
{
    int n;
    cin>>n;

    int ans = fibonacci(n);
    cout<<ans<<endl;

}