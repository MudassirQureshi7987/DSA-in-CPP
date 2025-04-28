#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;
class Solution {
    public:
      void topoSort(int node,vector<vector<pair<int,int>>> &adj,vector<int>& vis,stack<int>& s)
      {
          vis[node] = 1;
          
          for(auto it : adj[node])
          {
              if(!vis[it.first])
              {
                  topoSort(it.first,adj,vis,s);
              }
          }
          
          s.push(node);
      }
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          vector<vector<pair<int,int>>> adj(V);
          
          for(int i = 0;i < E;i++)
          {
              adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          }
          
          
          vector<int> vis(V,0);
          stack<int> s;
          
          for(int i = 0;i < V;i++)
          {
              if(!vis[i])
              {
                  topoSort(i,adj,vis,s);
              }
          }
          
          vector<int> dist(V,INT_MAX);
          
          dist[0] = 0;
          
          while(!s.empty())
          {
              int node = s.top();
              s.pop();
              
              if(dist[node] != INT_MAX)
              {
                  for(auto it : adj[node])
                  {
                      int v = it.first;
                      int wt = it.second;
                      
                      if(dist[node] + wt < dist[v])
                      {
                          dist[v] = dist[node] + wt;
                      }
                  }
              }
          }
          
                  // 5) Convert INF → -1 and cast back to int
          vector<int> ans(V);
          for (int i = 0; i < V; i++) {
              ans[i] = (dist[i] == INT_MAX ? -1 : int(dist[i]));
          }
          return ans;
      
      }
  };