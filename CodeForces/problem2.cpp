#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i)
            cin >> nums[i];

        sort(nums.rbegin(), nums.rend()); // Sort in descending order

        int paid = 0;
        int i = 0;

        // Step 1: Pay for all elements greater than c
        while(i < n && nums[i] > c) {
            paid++;
            i++;
        }

        // Step 2: Try to take elements that can be processed, in order, using doubling multiplier
        int factor = 1;
        while(i < n) {
            if(1LL * nums[i] * factor <= c) {
                factor *= 2;
                i++;
            } else {
                paid++;
                i++;
            }
        }

        cout << paid << '\n';
    }

    return 0;
}


