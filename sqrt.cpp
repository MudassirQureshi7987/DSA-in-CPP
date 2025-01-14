#include<iostream>
using namespace std;

long long int binarySearch(int x)
{
    int s=0;
    int e=x;
    long long int mid=s+(e-s)/2;
    long long int ans = -1;

    while(e>=s)
    {
        long long int sqr=mid*mid;
        if(sqr==x)
        {
            return mid; 
        }
        else if(sqr>x)
        {
            e=mid-1;
        }
        else
        {
            ans=mid;
            s=mid+1;
        }
         mid=s+(e-s)/2;

    }
    return ans;
}

double morePrecision(int n,int precision,int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for(int i=0;i<precision;i++)
    {
        factor = factor/10;
        for(double j=ans;j*j<n;j = j+factor)
        {
            ans = j;
        }
    }
    return ans;
}


int main()
{
    int n;
    cout<<"Enter the value of the number:";
    cin>>n;

    int tempSol=binarySearch(n);
    cout<<"Sqrt is "<<morePrecision(n,3,tempSol);
}