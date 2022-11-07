class Solution {
public:
    int fun(int idx , int sum , int target , vector<int> &nums , vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(sum == target){
                return 1;
            }
            else return 0;
        }
        if(dp[idx][sum + 1000] != -1){
            return dp[idx][sum + 1000];
        }
        int minus = fun(idx + 1 , sum - nums[idx] , target , nums , dp);
        int plus =  fun(idx + 1, sum + nums[idx] , target , nums , dp);
        
        return dp[idx][sum + 1000] = minus + plus;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(21, vector<int>(2001, -1));
        return fun(0 , 0 , target , nums , dp);
    }
};