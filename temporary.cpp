class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end(),[](const vector<int>& a, const vector<int>& b)
            {
                if(a[0] == b[0])
                {
                    return a[1] < b[1];
                }
                return a[0] < b[0];
            });
    
            int sum = 0;
            int maxi = INT_MIN;
            for(int i = 0;i < meetings.size() - 1;i++)
            {
                sum += meetings[i+1][0] - meetings[i][1];
                maxi = max(maxi,meetings[i][1]);
            }
    
            maxi = max(maxi,meetings[meetings.size()-1][1]);
            sum += days - maxi;
    
            return sum;
        }
    };