#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj) {
    int v = adj.size();
    vector<int> indegree(v,0);
    
    for(int i = 0;i < v;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    
    vector<int> topo;
    queue<int> q;
    
    for(int i = 0;i < v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        topo.push_back(front);
        
        for(auto it:adj[front])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    
    return topo;
 }

string getAlienLanguage(vector<string> &words, int k)
{
     vector<vector<int>> adj(26);
     
     for(int i = 0;i < words.size()-1;i++)
     {
         string str1 = words[i];
         string str2 = words[i+1];
         
         int len = min(str1.length(),str2.length());
         
         for(int j = 0;j < len;j++)
         {
             if(str1[j] != str2[j])
             {
                 adj[str1[j]-'a'].push_back(str2[j]-'a');
                 break;
             }
         }
     }
     
     vector<int> topo = topologicalSort(adj);
     
     string ans = "";
     
     for(auto it:topo)
     {
         ans += char(it + 'a');
     }
     return ans;

}