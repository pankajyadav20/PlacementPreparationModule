class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int i = 0 , j = 0, n = nums.size() , ans = 0 , sum = 0; 
        
        while(j < n){
            sum += nums[j];
            mp[nums[j]]++;
            if(mp.size() == j - i + 1){
                ans = max(ans , sum);
                j++;
            }else if(mp.size() < j - i + 1){
                while(mp.size() < j - i + 1){
                    mp[nums[i]]--;
                    sum -= nums[i];
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};