#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

    public:
        vector<int> rank,parent,size;
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0;i <= n;i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) // find ultimate parent
        {
            if(parent[node] == node)
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
            {
                return ;
            }
            
            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_v] == rank[ulp_u])
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
            {
                return ;
            }

            
            if(size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else // this case will also cover the case when size[ulp_u] == size[ulp_v]
                // because we are not using rank here
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)  == ds.findUPar(v))
            {
                cntExtras++;
            }
            else
            {
                ds.unionBySize(u,v);
            }
        }
        
        int nc = 0;
        for(int i = 0;i < n;i++)
        {
            if(ds.parent[i] == i)   nc++;
        }
        
        int ans = nc - 1;
        
        if(ans <= cntExtras)    return ans;
        return -1;
    }
};