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

void updateQuery(int idx,int left,int right,int updateIdx,int value,vector<int>& segTree)
{
    if(left == right) // reached at the desired index
    {
        segTree[idx] = value;
        return ;
    }

    int mid = left + (right - left)/2;

    if(updateIdx <= mid)
    {
        updateQuery(2*idx + 1,left,mid,updateIdx,value,segTree);
    }
    else
    {
        updateQuery(2*idx + 2,mid + 1,right,updateIdx,value,segTree);
    }

    segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
}

int rangeSum(int idx, int left, int right, int start, int end, vector<int>& segTree)
{
    if(start > right || end < left)   // fully out of bound so return 0
    {
        return 0;
    }
    else if(start <= left && end >= right) // fully inside the range so return the value of the node
    {
        return segTree[idx];
    }

    int mid = left + (right - left)/2;
    int lhs = rangeSum(2*idx + 1,left,mid,start,end,segTree);
    int rhs = rangeSum(2*idx + 2,mid+1,right,start,end,segTree);

    return lhs + rhs;
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