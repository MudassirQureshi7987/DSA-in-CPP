#include <bits/stdc++.h>
using namespace std;

// Function to build the segment tree
void buildTree(int idx, int left, int right, vector<int>& arr, vector<int>& segTree) {
    if (left == right) {
        segTree[idx] = arr[left];
        return;
    }

    int mid = (left + right) / 2;
    buildTree(2 * idx + 1, left, mid, arr, segTree);
    buildTree(2 * idx + 2, mid + 1, right, arr, segTree);

    segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}

// Range update with lazy propagation
void rangeUpdate(int idx, int left, int right, int l, int r, vector<int>& segTree, vector<int>& lazy, int value) {
    if (lazy[idx] != 0) {
        segTree[idx] += lazy[idx] * (right - left + 1);
        if (left != right) {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (left > r || right < l)
        return;

    if (left >= l && right <= r) {
        segTree[idx] += value * (right - left + 1);
        if (left != right) {
            lazy[2*idx+1] += value;
            lazy[2*idx+2] += value;
        }
        return;
    }

    int mid = (left + right) / 2;
    rangeUpdate(2*idx+1, left, mid, l, r, segTree, lazy, value);
    rangeUpdate(2*idx+2, mid+1, right, l, r, segTree, lazy, value);

    segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}

// Range sum query
int rangeQuery(int idx, int left, int right, int l, int r, vector<int>& segTree, vector<int>& lazy) {
    if (lazy[idx] != 0) {
        segTree[idx] += lazy[idx] * (right - left + 1);
        if (left != right) {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (left > r || right < l)
        return 0;

    if (left >= l && right <= r)
        return segTree[idx];

    int mid = (left + right) / 2;
    return rangeQuery(2*idx+1, left, mid, l, r, segTree, lazy) +
           rangeQuery(2*idx+2, mid+1, right, l, r, segTree, lazy);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> segTree(4 * n);
    vector<int> lazy(4 * n, 0);
    
    buildTree(0, 0, n - 1, arr, segTree);
    cout << "Segment Tree built successfully." << endl;

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int l, r, value;
        cout << "\nEnter update range (l r): ";
        cin >> l >> r;
        cout << "Enter value to add: ";
        cin >> value;

        if (l < 0 || r >= n || l > r) {
            cout << "Invalid range!" << endl;
            continue;
        }

        rangeUpdate(0, 0, n - 1, l, r, segTree, lazy, value);
        cout << "Now the sum of that range becomes: "
             << rangeQuery(0, 0, n - 1, l, r, segTree, lazy) << endl;
    }

    return 0;
}