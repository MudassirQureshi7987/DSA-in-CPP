// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void buildTree(int idx,int left,int right,int *arr,vector<int>& segTree)
    {
        if(left == right)
        {
            segTree[idx] = arr[left];
            return ;
        }
        
        int mid = left + (right - left)/2;
        buildTree(2*idx + 1,left,mid,arr,segTree);
        buildTree(2*idx + 2,mid + 1,right,arr,segTree);
        
        segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
    }
    
    int rangeSum(int idx,int left,int right,int& start,int& end,vector<int>& segTree)
    {
        // there can be exactly 3 cases
        // 1st case : totally outside the range
        if(end < left || start > right)
        {
            return 0;
        }
        else if(left >= start && right <= end) // 2nd case : totally inside the range
        {
            return segTree[idx];
        }
        
        // 3rd case : overlapping case when some part inside and some outside
        int mid = left + (right-left)/2;
        int lhs = rangeSum(2*idx + 1,left,mid,start,end,segTree);
        int rhs = rangeSum(2*idx + 2,mid+1,right,start,end,segTree);
        
        return lhs + rhs;
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        
        vector<int> segTree(4*n,0);
        buildTree(0,0,n-1,arr,segTree);
        vector<int> ans;
        
        for(int i = 0;i < 2*q;i += 2)
        {
            int start = queries[i] - 1;
            int end = queries[i+1] - 1;
            ans.push_back(rangeSum(0,0,n-1,start,end,segTree));
        }
        return ans;
    }
};