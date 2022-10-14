class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int> pre;
        pre.push_back(nums[0]);
        for(int i = 1; i < nums.size() ; i++){
             pre.push_back ( pre[i-1] + nums[i] );            
        }
        
        int left =  0 , ans = INT_MAX;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
                left += nums[i];
            if(pre[i]== left){
                    ans = min(ans , i); 
            }
             
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};