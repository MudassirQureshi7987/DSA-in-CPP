#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          vector<int> dist(V,1e8);
          dist[src] = 0;
          
          
      for(int j = 1;j < V;j++)
      {    
          for(int i = 0;i < edges.size();i++)
          {
              int u = edges[i][0];
              int v = edges[i][1];
              int wt = edges[i][2];
              
              if(dist[u] != 1e8)
              {
                  if(dist[u] + wt < dist[v])
                  {
                      dist[v] = dist[u] + wt;
                  }
              }
          }
      }
      
      bool flag = 1;
      
      for(int i = 0;i < edges.size();i++)
      {
          int u = edges[i][0];
          int v = edges[i][1];
          int wt = edges[i][2];
          
          if(dist[u] != 1e8)
          {
              if(dist[u] + wt < dist[v])
              {
                  flag = 0;
                  dist[v] = dist[u] + wt;
              }
          }
      }
      
      if(flag)
      {
          return dist;
      }
      return {-1};
          
      }
  };