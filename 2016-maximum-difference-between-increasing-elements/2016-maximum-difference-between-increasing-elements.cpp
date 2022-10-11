class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int mini = nums[0]  , ans = INT_MIN;
        for(int i = 0; i < nums.size() ; i++){
            if(mini > nums[i]){
                mini = nums[i];
            }
            
            ans = max(ans , nums[i] - mini);
        }
        if(ans == 0){
            return -1;
        }
        return ans;
    }  
};