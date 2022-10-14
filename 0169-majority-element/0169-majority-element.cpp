class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
            unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int cnt = 0;
        for(auto it : mp){
            if(it.second > n /2){
                cnt = it.first;
            }
        }
        return cnt;
    }
};