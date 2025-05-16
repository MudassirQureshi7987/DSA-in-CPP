#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node,vector<vector<int>> &adj,vector<int>& vis,stack<int>& st)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    void dfs1(int node,vector<vector<int>> &adj,vector<int>& vis)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs1(it,adj,vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
       
       int n = adj.size();
       stack<int> st;
       vector<int> vis(n,0);
       for(int i = 0;i < n;i++)
       {
           if(!vis[i])
           {
               dfs(i,adj,vis,st);
           }
       }
        
        
        vector<vector<int>> adjr(n);
        for(int i = 0;i < n;i++)
        {
            for(auto it : adj[i])
            {
                int node = i;
                int adjNode = it;
                
                adjr[adjNode].push_back(node);
            }
        }
        
        for(int i = 0;i < n;i++)    vis[i] = 0;
        int cnt = 0;
        while(!st.empty())
        {
            int node = st.top();st.pop();
            
            if(!vis[node])
            {
                dfs1(node,adjr,vis);
                cnt++;
            }
            
        }
        return cnt;
    }
};