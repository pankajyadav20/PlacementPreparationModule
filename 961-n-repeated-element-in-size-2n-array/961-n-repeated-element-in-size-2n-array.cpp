class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int ans;
        for(auto it : mp){
            if(it.second == N/2){
                ans = it.first;
            }
        }
        return ans;
    }
};