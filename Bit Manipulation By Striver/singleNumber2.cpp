#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; i += 3) {
            if (nums[i-1] != nums[i]) {
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
            int cnt = 0;
            for (int num : nums) {
                if (num & (1 << bitIndex)) {
                    cnt++;
                }
            }
            if (cnt % 3 != 0) {
                ans |= (1 << bitIndex);
            }
        }

        // Handle negative numbers (sign bit)
        if ((ans >> 31) & 1) {
            ans -= (1LL << 32);
        }

        return ans;
    }
};