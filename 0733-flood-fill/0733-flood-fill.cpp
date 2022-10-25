class Solution {
    void dfs(int i , int j , vector<vector<bool>> &visited , vector<vector<int>> &grid , int col,int newCol ){
        
          int dx[] = {-1,+1,0,0};
            int dy[] = {0,0,+1,-1};
        visited[i][j] = 1;
             int m = grid.size();
             int n = grid[0].size();
        grid[i][j] = newCol;
         for(int k = 0 ;k < 4;  k++){
                                  int  neighRow = i + dx[k];
                                  int  neighCol = j + dy[k];
                                    
                                      if(neighRow >=0 && neighRow < m
                                      && neighCol >=0 && neighCol < n
                                      && !visited[neighRow][neighCol]
                                      && grid[neighRow][neighCol] == col
                                      ){
                                        // cout<<neighRow<<" "<<neighCol<<endl;
                                        visited[neighRow][neighCol] = 1;
                                          grid[neighRow][neighCol] = newCol;
                                          dfs(neighRow , neighCol,visited,grid , col , newCol);
                                    }
                                }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
     
             int m = grid.size();
             int n = grid[0].size();
        
               vector<vector<bool>> visited(m , vector<bool>(n , 0));
            int col = grid[sr][sc];
            dfs(sr , sc , visited, grid , col , color);
        return grid;
    }
};