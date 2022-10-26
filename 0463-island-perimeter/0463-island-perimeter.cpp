class Solution {
    public:
    int bfs(vector<vector<int>>&grid,int m,int n,int i,int j,int perimeter){
        int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
   

      perimeter+=4;
      for(int k=0;k<4;k++) {
         int r=i+dx[k];
         int c=j+dy[k];  
         if (r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0) continue;
         perimeter -= 1;
       }
      return perimeter;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                   ans=bfs(grid,m,n,i,j,ans);
        return ans;
    }

};