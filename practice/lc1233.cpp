#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool prefixCheck(string& str,string& folder)
    {
        int n = str.length();
        int m = folder.length();

        if(m <= n)  return false;

        int i = 0;
        while(i < n)
        {
            if(str[i] == folder[i])
            {
                i++;
            }
            else
            {
                return false;
            }
        }

        if(folder[i] == '/')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n = folder.size();
        int i = 0;
        vector<string> ans;

        while(i < n)
        {
            string str = folder[i];
            ans.push_back(str);
            i++;

            while(i < n && prefixCheck(str,folder[i]))
            {
                i++;
            }
        }
        return ans;
    }
};