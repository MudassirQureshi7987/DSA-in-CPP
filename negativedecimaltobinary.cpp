#include<iostream>
#include<math.h>
using namespace std;

int decimalToBinary(int n)
{
    int i=0;
    float answer=0;
     while(n!=0)
    {
        int bit=n & 1;
        answer=(bit * pow(10 , i)) + answer;
        i++;
        
    }
    return answer;

}
 int main()
 {
    int n;
    cin>>n;
    
    if(n<0){
        n = n*(-1);
         int answer=decimalToBinary(n);
        // finding 2's compliment
        // first find 1's compliment
        float newAnswer = (~answer);
        // adding 1 to get 2's compliment
        newAnswer += 1;
        cout<<newAnswer<<endl;
    }
    else{
      float answer=decimalToBinary(n);
        cout<<answer<<endl;
    }
 }