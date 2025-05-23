#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool dfs(int node,vector<vector<int>> &adj,vector<int>& vis,vector<int>& pathvis,vector<int>& check)
        {
            vis[node] = 1;
            pathvis[node] = 1;
            check[node] = 0;
            
            for(auto neighbour:adj[node])
            {
                if(!vis[neighbour])
                {
                    if(dfs(neighbour,adj,vis,pathvis,check)== true)   
                    {
                        
                        return true;
                    }
                }
                else if(pathvis[neighbour] == 1)
                {
                    return true;
                }
            }
            
            check[node] = 1;
            pathvis[node] = 0;
            return false;
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
    
            vector<int> vis(n,0);
            vector<int> pathvis(n,0);
            vector<int> check(n,0);
            
            for(int i = 0;i < n;i++)
            {
                dfs(i,graph,vis,pathvis,check);
            }
    
            vector<int> safeNodes;
            for(int i = 0;i < n;i++)
            {
                if(check[i] == 1)
                    safeNodes.push_back(i);
            }
    
            return safeNodes;
        }
    };