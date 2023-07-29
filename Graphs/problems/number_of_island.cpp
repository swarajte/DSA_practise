#include <bits/stdc++.h> 
using namespace std;

void bfs(int row,int col,vector<vector<int>> &visi,vector<vector<char>> &grid){
    visi[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});

    //traversing in neighbours
    while(!q.empty()){
        pair<int,int> top=q.front();
        int row=top.first;
        int col=top.second;

        for(int delrow=-1; delrow<=1; delrow++){
            for(int delcol=-1; delcol<=1; delcol++){
                int nrow=row+delrow;
                int ncol=col+delcol;
                //bounfry condition
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()){
                     if(grid[nrow][ncol]=='1' && !visi[nrow][ncol]){
                        visi[nrow][ncol]=true;
                        q.push({nrow,ncol});
                     }
                }
            }
        }

    }
}

int numIslands(vector<vector<char>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> visi(n,vector<int>(m,0));

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           if(!visi[i][j] && grid[i][j]=='1'){
               cnt++;
               bfs(i,j,visi,grid);
           }
        }  
    }

    return cnt;    
}

int main()
{

    return 0;
}