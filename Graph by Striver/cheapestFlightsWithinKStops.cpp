#include<iostream>
#include<vector>
#include<queue>
#include<pair>
using namespace std;

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            
            vector<vector<pair<int,int> > > adj(n+1);
    
            for(int i = 0;i < flights.size();i++)
            {
                adj[flights[i][0]].push_back({ flights[i][1], flights[i][2]});
            }
    
                    // {stops, {node,distance}}
            queue<pair<int,pair<int,int> > > q;
            q.push({ 0,{ src, 0}});
            vector<int> dist(n,INT_MAX);
            dist[src] = 0;
    
            while(!q.empty())
            {
                int node = q.front().second.first;
                int stops = q.front().first;
                int distance = q.front().second.second;
                q.pop();
    
                if(stops > k)   continue;
    
                for(auto iter : adj[node])
                {
                    int adjNode = iter.first;
                    int adjDis = iter.second;
    
                    if(distance + adjDis < dist[adjNode] && stops <= k)
                    {
                        dist[adjNode] = distance + adjDis;
                        q.push({ stops + 1,{ adjNode, dist[adjNode]}});
                    }
                }
            }
    
            if(dist[dst] != INT_MAX)    return dist[dst];
            return -1;
        }
    };