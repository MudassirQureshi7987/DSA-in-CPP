#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void buildTree(int idx, int left, int right, vector<int>& baskets, vector<int>& segTree) {
        if (left == right) {
            segTree[idx] = baskets[left];
            return;
        }

        int mid = left + (right - left) / 2;
        buildTree(2 * idx + 1, left, mid, baskets, segTree);
        buildTree(2 * idx + 2, mid + 1, right, baskets, segTree);

        segTree[idx] = max(segTree[2 * idx + 1], segTree[2 * idx + 2]);
    }

    void updateTree(int idx, int left, int right, int& fruit, vector<int>& segTree) {
        if (left == right) {
            segTree[idx] = 0;
            return;
        }

        int mid = left + (right - left) / 2;

        if (segTree[2 * idx + 1] >= fruit) {
            updateTree(2 * idx + 1, left, mid, fruit, segTree);
        } else {
            updateTree(2 * idx + 2, mid + 1, right, fruit, segTree);
        }

        segTree[idx] = max(segTree[2 * idx + 1], segTree[2 * idx + 2]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4 * n);
        buildTree(0, 0, n - 1, baskets, segTree);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (fruits[i] > segTree[0]) {
                cnt++;
                continue;
            }

            updateTree(0, 0, n - 1, fruits[i], segTree);
        }

        return cnt;
    }
};