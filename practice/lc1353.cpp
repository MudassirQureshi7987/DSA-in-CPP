#include<bits/stdio.h>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b)
    {
        if(a[1] == b[1])
        {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int max_len = 1;

        for(auto &e : events)
        {
            max_len = max(max_len,e[1]);
        }

        vector<bool> days(max_len + 1,false);

        sort(events.begin(),events.end(),cmp);

        int cnt = 0;
        for(int i = 0;i < n;i++)
        {
            for(int day = events[i][0];day <= events[i][1];day++)
            {
                if(!days[day])
                {
                    days[day] = true;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};