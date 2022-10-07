class Solution {
public:
    int fun(int idx1 , int idx2 , vector<vector<int>> grid){
        if(idx1 == 0 && idx2 == 0){
            return grid[0][0];
        }
        if(idx1 < 0 || idx2 < 0){
            return INT_MAX;
        }
        return min(fun(idx1-1 , idx2 , grid) , fun(idx1 , idx2 - 1, grid)) + grid[idx1][idx2];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        
        // return fun(n - 1 , m - 1, grid);
        
        vector<vector<int>> dp(n ,  vector<int>( m,  0));
        dp[0][0] = grid[0][0];
        for(int i= 0 ;  i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(i == 0 && j == 0){
                dp[0][0] = grid[0][0];
                }
                 else  { int up = grid[i][j];
                        if(i>0) up += dp[i-1][j];
                        else up += 1e9;

                        int left = grid[i][j];
                        if(j>0) left+=dp[i][j-1];
                        else left += 1e9;

                        dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};