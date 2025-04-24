#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
    public:
      void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &temp,int row0,int col0)
      {
          vis[row][col] = 1;
          int r = row - row0;
          int c = col - col0;
          temp.push_back(make_pair(r,c));
          int n = grid.size();
          int m = grid[0].size();
          
          int delRow[] = {-1,0,+1,0};
          int delCol[] = {0,+1,0,-1};
          
          for(int i = 0;i < 4;i++)
          {
              int nRow = row + delRow[i];
              int nCol = col + delCol[i];
              
              if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                  !vis[nRow][nCol] && grid[nRow][nCol] == 1)
                  {
                      dfs(nRow,nCol,grid,vis,temp,row0,col0);
                  }
          }
      }
      int countDistinctIslands(vector<vector<int>>& grid) {
          int n = grid.size();
          int m = grid[0].size();
          
          vector<vector<int> > vis(n,vector<int>(m,0));
          
          set<vector<pair<int,int>>> s;
          
          for(int i = 0;i < n;i++)
          {
              for(int j = 0;j < m;j++)
              {
                  if(!vis[i][j] && grid[i][j] == 1)
                  {
                      vector<pair<int,int>> temp;
                      dfs(i,j,grid,vis,temp,i,j);
                      s.insert(temp);
                  }
              }
          }
          
          return s.size();
      }
  };