class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> dp(n);
       
        
        for(int i = 0; i < n ; i++){
            vector<int> temp;
            for(int j = 0 ; j <= i ; j++){
                if(j == 0 || j == i){
                    dp[i].push_back(1);
                }
                else
                 dp[i].push_back( dp[i-1][j] + dp[i - 1][j-1]);
            }
            // dp.push_back(temp);
        }
        return dp;   
    }
};