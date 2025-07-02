#include<iostream>
#include<vector>
#include<algorithm>
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
// User function Template for C++
class Solution {
  public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[2] < b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),cmp);
        
        DisjointSet ds(V);
        int mstWt = 0;
        for(int i = 0;i < edges.size();i++)
        {
            int node = edges[i][0];
            int adjNode = edges[i][1];
            int wt = edges[i][2];
            
            if(ds.findUPar(node) != ds.findUPar(adjNode))
            {
                mstWt += wt;
                ds.unionBySize(node,adjNode);
            }
        }
        
        return mstWt;
    }
};

class Solution {
    public:
  
      int spanningTree(int V, vector<vector<int>> adj[]) {
          
          vector<pair<int,pair<int,int>>> edges;
          
          for(int i = 0;i < V;i++)
          {
              for(auto it : adj[i])
              {
                  int node = i;
                  int adjNode = it[0];
                  int wt = it[1];
                  
                  edges.push_back({wt,{node,adjNode}});
              }
          }
          
          sort(edges.begin(),edges.end());
          
          DisjointSet ds(V);
          int mstWt = 0;
          for(int i = 0;i < edges.size();i++)
          {
              int node = edges[i].second.first;
              int adjNode = edges[i].second.second;
              int wt = edges[i].first;
              
              if(ds.findUPar(node) != ds.findUPar(adjNode))
              {
                  mstWt += wt;
                  ds.unionBySize(node,adjNode);
              }
          }
          
          return mstWt;
      }
  };