#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<stack>
#include<limits.h>
using namespace std;

class Graph
{
    public:
        unordered_map<int,list<pair<int,int> > > adj;

    void addEdge(int u,int v,int weight)
    {
        pair<int,int> p = make_pair(v,weight);

        adj[u].push_back(p);
    }

    void printAdj()
    {
        for(auto i:adj)
        {
            cout<< i.first <<"->";

            for(auto j:i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<"),";
            }cout<<endl;
        }
    }

    void dfs(int i,unordered_map<int,bool> &visited,stack<int> &s)
    {
        visited[i] = true;

        for(auto j:adj[i])
        {
            if(!visited[j.first])
            {
                dfs(j.first,visited,s);
            }
        }

        s.push(i);
    }

    void getShortestPath(int src,vector<int> &dist,stack<int> &s)
    {
        dist[src] = 0;

        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX)
                for(auto i:adj[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    // topoSort
    int n = 6;
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i = 0;i < n;i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited,s);
        }
    }

    vector<int> dist(n);
    int src = 1;

    for(int i = 0;i < n;i++)
    {
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src,dist,s);

    cout<<"The answer is "<<endl;

    for(int i = 0;i < n;i++)
    {
        cout<<dist[i]<<" ";
    }cout<<endl;
}