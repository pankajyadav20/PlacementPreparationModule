class Solution {
public:
    int fun(int i, int j ,vector<vector<int>> &triangle , vector<vector<int>> &dp){
        if(i == 0){
            return triangle[0][0];
        }
        if(j >= triangle[i].size()){
            return 1e9;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
         int up = fun( i - 1 , j , triangle ,dp);  
         int upNext = fun(i - 1, j - 1, triangle , dp);
        
            return dp[i][j] = ( triangle[i][j] + min(up , upNext) );
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int mini = 1e9 , n = triangle.size() ;
        for(int i = 0 ; i< triangle.size() ; i++){
            vector< vector<int> > dp( n , vector<int>(n , -1));
            mini = min( mini , fun( n - 1, i, triangle ,dp));
        }
        return mini;
    }
};