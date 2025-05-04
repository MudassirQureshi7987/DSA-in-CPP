#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int,int>>> adj(n);
    
            for(int i = 0;i < roads.size();i++)
            {
                adj[roads[i][0]].push_back({ roads[i][1], roads[i][2]});
                adj[roads[i][1]].push_back({ roads[i][0], roads[i][2]});
            }
    
              // {distance,node}
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,
                            greater<pair<long long,int>> > pq;
    
            vector<long long> dist(n,LLONG_MAX);
            vector<long long> ways(n,0);
            dist[0] = 0;
            ways[0] = 1;
            pq.push({0,0});
            int mod = (int)(1e9+7);
            while(!pq.empty())
            {
                int node = pq.top().second;
                long long distance = pq.top().first;
                pq.pop();
    
                if(distance > dist[node])   continue;
    
                for(auto it : adj[node])
                {
                    long long adjNode = it.first;
                    long long adjDis = it.second;
    
                    if(distance + adjDis == dist[adjNode])
                    {
                        ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                    }
                    else if(distance + adjDis < dist[adjNode])
                    {
                        dist[adjNode] = distance + adjDis;
                        ways[adjNode] = ways[node]%mod;
                        pq.push({dist[adjNode],adjNode});
                    }
                }
            }
    
           return (int)ways[n-1]%mod;
        }
    };