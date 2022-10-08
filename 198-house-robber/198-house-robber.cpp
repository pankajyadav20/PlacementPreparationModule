class Solution {
public:
    int helper(int idx  , vector<int> &nums){
        
        if(idx < 0){
            return 0;
        }
        if(idx == 0){
            return nums[idx];
        }
        int notTake = 0 + helper( idx - 1 , nums);
        int take = nums[idx] + helper(idx - 2, nums);
        
        return max(notTake , take);
        
    }
    int rob(vector<int>& nums) {
        int  n = nums.size();
        vector<int> dp(n , - 1);
        // return  helper( nums.size() - 1, nums);
        
        dp[0] = nums[0];
        for(int idx = 1 ;idx < nums.size() ; idx++){
                int notTake = 0 + dp[idx - 1];
                int take = nums[idx] ;
                if(idx > 1) 
                    take += dp[idx - 2];
            dp[idx] = max(take , notTake);
        }
        return dp[n-1];
    }
};