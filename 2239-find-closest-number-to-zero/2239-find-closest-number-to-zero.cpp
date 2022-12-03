class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
        int mini = abs(nums[0]);
        for(int i  = 0 ; i < nums.size() ; i++){
            mini = min ( mini , abs(nums[i]));
        }
        int ans = -1e9;
        for(auto it : nums){
            if(abs(it) == mini){
                ans = max(it , ans);
            }
        }
        return ans;
    }
};