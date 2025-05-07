#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[]) {
          
          priority_queue<pair<int,int>,vector<pair<int,int>>,
                          greater<pair<int,int>> > pq;
                          
          vector<int> vis(V,0);
          
          pq.push({0,0});
          int sum = 0;
          while(!pq.empty())
          {
              int node = pq.top().second;
              int wt = pq.top().first;
              pq.pop();
              
              if(vis[node])   continue;
              
              vis[node] = 1;
              sum += wt;
              
              for(auto it : adj[node])
              {
                  int adjNode = it[0];
                  int adjwt = it[1];
                  
                  if(!vis[adjNode])
                  {
                      pq.push({adjwt,adjNode});
                  }
              }
          }
          return sum;
      }
  };