#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int cnt = 0;
        multiset<long> prefixSet;
        prefixSet.insert(0);

        long prefixSum = 0;
        for(int i = 0;i < n;i++)
        {
            prefixSum += nums[i];

            auto low = prefixSet.lower_bound(prefixSum - upper);
            auto high = prefixSet.upper_bound(prefixSum - lower);

            cnt += distance(low,high);
            prefixSet.insert(prefixSum);
        }
        return cnt;
    }
};