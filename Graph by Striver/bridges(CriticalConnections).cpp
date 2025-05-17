#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS function to find bridges (critical connections)
    void dfs(int node, int parent, vector<vector<int>> &adj,
             vector<int>& vis, vector<int>& tin, vector<int>& low,
             vector<vector<int>>& ans, int& step)
    {
        vis[node] = 1; // Mark current node as visited
        tin[node] = low[node] = step; // Initialize discovery time and low time

        for (auto neigh : adj[node]) {
            if (neigh == parent)
                continue; // Skip the edge leading back to parent

            if (!vis[neigh]) {
                step = step + 1; // Increment step for discovery time
                dfs(neigh, node, adj, vis, tin, low, ans, step); // DFS on unvisited neighbor

                // After recursion, update low time of current node
                low[node] = min(low[node], low[neigh]);

                // Check if the edge is a bridge
                if (tin[node] < low[neigh]) {
                    vector<int> temp = {node, neigh}; // Store the bridge
                    ans.push_back(temp);
                }
            }
            else {
                // If the neighbor is already visited and not parent, it's a back edge
                low[node] = min(low[node], low[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create adjacency list for the graph
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected
        }

        vector<int> vis(n, 0);   // Visited array
        vector<int> tin(n);     // Discovery time of each node
        vector<int> low(n);     // Lowest discovery time reachable

        vector<vector<int>> ans; // Stores the result - list of bridges
        int step = 1; // Time step (can start from 0 or 1)

        dfs(0, -1, adj, vis, tin, low, ans, step); // Start DFS from node 0
        
        return ans;
    }
};