#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int timer = 1;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& vis
                ,vector<int>& tin,vector<int>& low,vector<int>& hash)
                {
                    vis[node] = 1;
                    tin[node] = low[node] = timer;
                    timer++;
                    int child = 0;
                    
                    for(auto it : adj[node])
                    {
                        if(it == parent)    continue;
                        if(!vis[it])
                        {
                            dfs(it,node,adj,vis,tin,low,hash);
                            low[node] = min(low[node],low[it]);
                            if(low[it] >= tin[node] && parent != -1)
                            {
                                hash[node] = 1;
                            }
                            child++;
                        }
                        else
                        {
                            low[node] = min(low[node],tin[it]);
                        }
                        
                    }
                    
                    if(child > 1 && parent == -1)
                    {
                        hash[node] = 1;
                    }
                }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> tin(V);
        vector<int> low(V);
        vector<int> hash(V,0);
        
        for(int i = 0;i < V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,adj,vis,tin,low,hash);
            }
        }
        
        vector<int> ans;
        for(int i = 0;i < V;i++)
        {
            if(hash[i])
            {
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};