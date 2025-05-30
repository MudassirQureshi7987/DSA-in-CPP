#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string decToBinary(int n) {
        string res = "";
        
        while(n != 1)
        {
            if(n % 2 == 0)  res += "0";
            else    res += "1";
            
            n = n/2;
        }
        
        res += "1";
        reverse(res.begin(),res.end());
        return res;
        
    }
};