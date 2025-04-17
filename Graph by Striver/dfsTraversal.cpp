#include<vector>
using namespace std;


// for undirected disconnected graph
void dfs(int node,vector<vector<int> > &adj,vector<int> &vis,vector<int> &temp)
{
    vis[node] = 1;
    temp.push_back(node);

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour,adj,vis,temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   // make adjacency list
   vector<vector<int> > adj(V);
   for(int i = 0;i < E;i++)
   {
       int u = edges[i][0];
       int v = edges[i][1];

       adj[u].push_back(v);
       adj[v].push_back(u);
   }

   vector<vector<int> > ans;
   vector<int> vis(V,0);

   for(int it = 0;it < V;it++)
   {
       if(!vis[it])
       {
           vector<int> temp;
           dfs(it,adj,vis,temp);
           ans.push_back(temp);
       }
   }

   return ans;
}



// for undirected connected graph
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
