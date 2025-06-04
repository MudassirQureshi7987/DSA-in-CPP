#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int n = arr.size();
        int xord = 0;
        for(int i = 0;i < n;i++)
        {
            xord ^= arr[i];
        }
        return xord;
    }
};