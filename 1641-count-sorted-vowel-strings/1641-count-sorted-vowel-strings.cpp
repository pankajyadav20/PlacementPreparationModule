class Solution {
public:
    int fun(int idx , int len , vector<vector<int>> &dp){
        
        if(len == 0){
            return 1;
        }
        if(idx >= 5){
            return 0;
        }
        if(dp[idx][len] != -1){
            return dp[idx][len];
        }
        int notTake = fun(idx + 1 , len  , dp);
        int take = fun( idx ,  len - 1 ,dp );
        
        return dp[idx][len] = take + notTake;
        
    }
    int countVowelStrings(int n) {
       vector< vector<int> > dp( 5 ,vector<int>(  n + 1 , -1) );
        return fun(0 , n  , dp);
        
    }
};