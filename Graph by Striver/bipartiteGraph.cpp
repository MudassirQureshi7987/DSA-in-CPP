#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool dfs(int node,int col,vector<int> &color,vector<vector<int>> &graph)
        {
            color[node] = col;
    
            for(auto neighbour:graph[node])
            {
                if(color[neighbour] == -1)  // if it has not been colored yet
                {
                    if(dfs(neighbour, !col ,color,graph) == false)  return false;;
                }
                else if(color[neighbour] == col) // if it has already been colored then check its color
                {
                    return false;
                }
            }
    
            return true;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n,-1);
    
            for(int i = 0;i < n;i++)
            {
                if(color[i] == -1)
                {
                    if(dfs(i,0,color,graph) == false)   return false;
                }
            }
    
            return true;
        }
    };