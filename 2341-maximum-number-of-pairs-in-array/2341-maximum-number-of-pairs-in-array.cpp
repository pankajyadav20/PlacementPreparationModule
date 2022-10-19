class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        unordered_map<int , int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int pair = 0 , temp = 0;
        
        for(auto it : mp){
           pair += it.second/2;
            if(it.second & 1){
                temp++;
            }
        }
        vector<int> ans;
        ans.push_back(pair);
        ans.push_back(temp);
        return ans;
    }
};