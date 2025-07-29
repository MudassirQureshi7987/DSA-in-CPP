/* The functions which
builds the segment tree */
#include<bits/stdc++.h>
using namespace std;

void buildTree(int idx,int left,int right,int *arr,int *segTree)
    {
        if(left == right)
        {
            segTree[idx] = arr[left];
            return ;
        }
        
        int mid = left + (right - left)/2;
        buildTree(2*idx + 1,left,mid,arr,segTree);
        buildTree(2*idx + 2,mid + 1,right,arr,segTree);
        
        segTree[idx] = min(segTree[2*idx+1],segTree[2*idx+2]);
    }
int *constructST(int arr[], int n) {
    int *st = new int(4*n);
    buildTree(0,0,n-1,arr,st);
    return st;
}

int rangeMin(int idx,int l,int r,int start,int end,int *segTree)
{
    if(r < start || l > end)    return INT_MAX;
    else if(l >= start && end >= r) return segTree[idx];
    
    int mid = l + (r-l)/2;
    return min(rangeMin(2*idx+1,l,mid,start,end,segTree),
                rangeMin(2*idx+2,mid+1,r,start,end,segTree));
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    
    return rangeMin(0,0,n-1,a,b,st);
    
}