#include<bits/stdc++.h>
using namespace std;

void buildTree(int idx,int left,int right,vector<int>& segTree,vector<int>& arr)
{
    if(left == right)
    {
        segTree[idx] = arr[left];
        return ;
    }

    int mid = left + (right - left)/2;
    buildTree( 2*idx + 1,left,mid,segTree,arr);
    buildTree( 2*idx + 2,mid + 1,right,segTree,arr);

    segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> segTree(2 * n, 0);
    buildTree(0,0,n-1,segTree,arr);
    //prefix sum query
    int l, r;
    cin >> l >> r;

    // int result = rangeSum(0,)
}