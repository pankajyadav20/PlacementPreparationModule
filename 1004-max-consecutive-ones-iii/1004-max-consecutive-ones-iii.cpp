class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0 , j = 0 , ans = 0 , n = nums.size();
        int temp = 0;
        while(j < n){
            if(nums[j] == 0){
                temp++;
            }
            if(temp <= k){
                ans = max(ans , j - i + 1);
                j++;
            }else if(temp > k){
                
                while(temp > k){
                    if(nums[i] == 0){
                        temp--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};