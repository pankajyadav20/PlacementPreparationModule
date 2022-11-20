class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1){
            return 0;
        }
        
        int ans = 0 , i = 0 , j = 0, n = nums.size();
        int pro = 1 , idx = 0;
        
        while(j < n){
            pro *= nums[j];
            if(pro < k){
                ans += j - i + 1;
                j++;
            }else if(pro >= k){
                while(pro >= k){
                    pro /= nums[i];
                    i++;
                }
                ans += j - i + 1;
                j++;
            }
        }
       
        return ans;
    }
};










