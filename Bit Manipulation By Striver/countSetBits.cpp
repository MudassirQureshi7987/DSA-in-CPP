// _builtin_popcount: This is a built-in function in GCC and Clang that counts the number of set bits (1s) in an integer.
#include <iostream> 
using namespace std;

// Function to count set bits using built-in function
int countSetBits(int n) {
    return __builtin_popcount(n);
}


class Solution {
  public:
    int setBits(int n) {
        int cnt = 0;
        
        while(n > 0)
        {
            cnt += n & 1;
            
            n = n >> 1;
        }
        return cnt;
    }
};

class Solution {
  public:
    int setBits(int n) {
       int cnt = 0;
       
       while(n != 0)
       {
           n = n & n-1;
           cnt++;
       }
       return cnt;
    }
};
// Explanation: