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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);
        
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        for(int row = 0;row < n;row++)
        {
            for(int col = 0;col < n;col++)
            {
                if(grid[row][col] == 0) continue;
                
                for(int ind = 0;ind < 4;ind++)
                {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n
                        && grid[nrow][ncol] == 1)
                        {
                            int nodeNo = row * n + col;
                            int adjNodeNo = nrow * n + ncol;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                }
            }
        }

        // step 2
        int maxi = 0;
        for(int row = 0;row < n;row++)
        {
            for(int col = 0;col < n;col++)
            {
                if(grid[row][col] == 1) continue;
                set<int> components;
                for(int ind = 0;ind < 4;ind++)
                {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n
                        && grid[nrow][ncol] == 1)
                        {
                            components.insert(ds.findUPar(nrow*n + ncol));
                        }
                }

                int sizeTotal = 0;
                for(auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                maxi = max(maxi,sizeTotal+1);
            }
        }

        for(int i = 0;i < n*n;i++)
        {
            maxi = max(maxi,ds.size[ds.findUPar(i)]);
        }
        return maxi;
    }
};