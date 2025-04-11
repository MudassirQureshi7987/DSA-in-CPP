#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
        {
            vis[node] = 1;
    
            for(auto neighbour:adj[node])
            {
                if(!vis[neighbour])
                {
                    dfs(neighbour,adj,vis);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            vector<vector<int>> adj(isConnected.size());
    
            for(int i = 0;i < isConnected.size();i++)
            {
                for(int j = 0;j < isConnected.size();j++)
                {
                    // avoid self loops with i != j
                    if(isConnected[i][j] == 1 && i != j)
                    {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
    
            //will do dfs now to get ans
            int cnt = 0;
            vector<int> vis(adj.size(),0);
    
            for(int i = 0;i < adj.size();i++)
            {
                if(!vis[i])
                {
                    cnt++;
                    dfs(i,adj,vis);
                    
                }
            }
    
            return cnt;
        }
    };

    // efficient version where we directly use the matrix to do dfs
    class Solution {
        public:
            void dfs(int node,vector<vector<int> > &isConnected,vector<int> &vis)
            {
                vis[node] = 1;
        
                for(int j = 0;j < isConnected.size();j++)
                {
                    if(isConnected[node][j] == 1 && !vis[j])
                    {
                        dfs(j,isConnected,vis);
                    }
                }
            }
            int findCircleNum(vector<vector<int>>& isConnected) {
                
                vector<int> vis(isConnected.size(),0);
                int cnt = 0;
        
                for(int i = 0;i < isConnected.size();i++)
                {
                    if(!vis[i])
                    {
                        dfs(i,isConnected,vis);
                        cnt++;
                    }
                }
        
                return cnt;
            }
        };