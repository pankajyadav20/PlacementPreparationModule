class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1){
            if(nums[0] == k){
                return 1; 
            }return 0;
        }
        int cnt = 0;
        unordered_map<int ,int> mp;
        int preSum = 0;
        mp[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            preSum += nums[i];
            if ( mp.find(preSum -k) != mp.end()){
                cnt+=mp[preSum-k];
            }
            mp[preSum]++;
        }
        // if(preSum == k){
        //     cnt++;
        // }
        return cnt;
    }
};