#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int i=0;
    int n;
    cin>>n;
    float answer=0;

    while(n!=0)
    {
        int bit=n & 1;
        answer=(bit * pow(10 , i)) + answer;
        i++;
        
    }
      cout<<"Answer is "<<answer<<endl;
}