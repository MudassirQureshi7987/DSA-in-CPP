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
    int removeStones(vector<vector<int>>& stones) {
        int row = 0;
        int col = 0;
        int n = stones.size();
        for(auto it : stones)
        {
            row = max(row,it[0]);
            col = max(col,it[1]);
        }

        DisjointSet ds(row + col + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it : stones)
        {
            int r = it[0];
            int c = it[1] + row + 1;
            ds.unionBySize(r,c);
            stoneNodes[r] = 1;
            stoneNodes[c] = 1;
        }

        int cnt = 0;
        for(auto it : stoneNodes)
        {
            if(ds.findUPar(it.first) == it.first)
            {
                cnt++;
            }
        }

        return n - cnt;
    }
};