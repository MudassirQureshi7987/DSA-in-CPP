#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binaryToDecimal(string &b) {
        int len = b.length();
        int two_power = 1;
        int ans = 0;
        for(int i = len-1;i >= 0;i--)
        {
            if(b[i] == '1')
            {
                ans += 1*two_power;
            }
            two_power = two_power*2;
        }
        return ans;
    }
};        