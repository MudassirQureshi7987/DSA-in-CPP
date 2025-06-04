#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        int subset = 1 << n;
        vector<string> ans;
        
        for(int i = 0;i < subset;i++)
        {
            string str = "";
            for(int j = 0;j <n;j++)
            {
                if( i & (1 << j))
                {
                    str.push_back(s[j]);
                }
            }
            ans.push_back(str);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};