#include<iostream>
using namespace std;

int fibonacci(int n,int& sum)
{
    //base case
    if(n==0 || n==1)
    {
        return n;
    }

     sum = sum + fibonacci(n-1,sum) + fibonacci(n-2,sum);

    


}

int main()
{
    int n;
    cin>>n;
    int sum = 1;

    fibonacci(n,sum);
    cout<<sum<<endl;

}