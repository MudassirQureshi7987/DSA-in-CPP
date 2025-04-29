#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
    public:
      // Function to find the shortest path from source to all other nodes
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
          // node,dist
          queue<pair<int,int>> q;
          vector<int> dist(adj.size(),INT_MAX);
          dist[src] = 0;
          
          q.push({src,0});
          
          while(!q.empty())
          {
              int node = q.front().first;
              int distance = q.front().second;
              q.pop();
              
              for(auto it : adj[node])
              {
                  if(distance + 1 < dist[it])
                  {
                      dist[it] = distance + 1;
                      q.push({it,dist[it]});
                  }
              }
          }
          
          
          for(int i = 0;i < adj.size();i++)
          {
              if(dist[i] == INT_MAX)
              {
                  dist[i] = -1;
              }   
              
          }
          return dist;
      }
  };