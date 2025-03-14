#include<iostream>
#include<set>
#include<vector>
#include<limits.h>
#include<unordered_map>
#include<list>
using namespace std;

vector<int> dijkstra(vector<vector<int> > &vec,int vertices,int edges,int source)
{
    // create adj list
    unordered_map<int,list<pair<int,int> > > adj;
    for(int i = 0;i < edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));
    }

    // creation of distance array with infinite value initially
    vector<int> dist(vertices);
    for(int i = 0;i < vertices;i++)
    {
        dist[i] = INT_MAX;
    }

    // pair is <weight,node> or <distance,node>
    set<pair<int,int> > st;

    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        // traverse on neighbours

        for(auto neighbour:adj[topNode])
        {
            if(nodeDistance + neighbour.second < dist[neighbour.first])
            {
                // if entry for that neighbour already exists then find it so we can delete it cause it is greater than the new one
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                
                // if record found then erase it
                if(record != st.end())
                {
                    st.erase(record);
                }

                //distance update

                dist[neighbour.first] = nodeDistance + neighbour.second;

                // record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first)); 
            }
        }
    }
    return dist;
}

int main()
{

}