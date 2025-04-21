#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
      bool detect(int node,vector<vector<int>> &adj,int vis[])
      {
          vis[node] = 1;
          queue<pair<int,int> > q;
          
          q.push(make_pair(node,-1));
          
          while(!q.empty())
          {
              int frontNode = q.front().first;
              int parent = q.front().second;
              q.pop();
              
              for(int neighbour:adj[frontNode])
              {
                  if(!vis[neighbour])
                  {
                      q.push(make_pair(neighbour,frontNode));
                      vis[neighbour] = 1;
                  }
                  else if(parent != neighbour)
                  {
                      return true;
                  }
              }
          }
          
          return false;
      }
      bool isCycle(int V, vector<vector<int>>& edges) {
          vector<vector<int> > adj(V);
          
          for(int i = 0;i < edges.size();i++)
          {
              int u = edges[i][0];
              int v = edges[i][1];
              
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          
          int vis[V] = {0};
          
          for(int i = 0;i < V;i++)
          {
              if(!vis[i])
              {
                  if(detect(i,adj,vis))
                  {
                      return true;
                  }
              }
          }
          
          return false;
          
      }
  };