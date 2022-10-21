class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0 , n = nums.size(); i < n ; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }else
                if(i - mp[nums[i]] <= k){
                    return 1;
                }else mp[nums[i]] = i;
        }
       return false;
    }
};