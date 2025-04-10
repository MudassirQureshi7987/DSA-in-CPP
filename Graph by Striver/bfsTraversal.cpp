#include<ostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(int i = 0;i < adj[frontNode].size();i++)
        {
            if(!visited[adj[frontNode][i]])
            {
                q.push(adj[frontNode][i]);
                visited[adj[frontNode][i]] = true;
            }
        }        
    }
}


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
   vector<int> ans;
   
   unordered_map<int,bool> visited;

 
           bfs(adj,visited,ans,0);
       
   return ans;
}