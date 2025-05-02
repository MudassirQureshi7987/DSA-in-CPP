#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;
class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
    
            vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
    
            queue<pair<int,pair<int,int> > > q;
            if(grid[0][0] == 0)
            {
                    dist[0][0] = 1;
                    q.push({ 1, {0,0}});
            }
    
            while(!q.empty())
            {
                int row = q.front().second.first;
                int col = q.front().second.second;
                int distance = q.front().first;
                q.pop();
                for(int i = -1;i <= 1;i++)
                {
                    for(int j = -1;j <= 1;j++)
                    {
                        int nRow = row + i;
                        int nCol = col + j;
    
                        if(nRow == row && nCol == col)
                        {
                            continue ;
                        }
    
                        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                            grid[nRow][nCol] == 0)
                            {
                                if(distance + 1 < dist[nRow][nCol])
                                {
                                    dist[nRow][nCol] = distance + 1;
                                    q.push({ dist[nRow][nCol],{nRow,nCol}});
                                }
                            }
                    }
                }
            }
    
            if(dist[n-1][n-1] != INT_MAX)
            {
                return dist[n-1][n-1];
            }
            return -1;
        }
    };