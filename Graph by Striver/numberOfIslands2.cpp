#include <bits/stdc++.h>    
using namespace std;

class DisjointSet
{
    vector<int> rank,parent,size;

    public:

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        vector<int> ans;
        int cnt = 0;
        
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        for(int i = 0;i < k;i++)
        {
            int row = operators[i][0];
            int col = operators[i][1];
            
            if(vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            for(int i = 0;i < 4;i++)
            {
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
                {
                    if(vis[nRow][nCol] == 1)
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = nRow * m + nCol;
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;  
    }
};