class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int first , second;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp[i+1] > 1){
                    first = i + 1;
            }
            if(mp[i+1] == 0){
                second = i + 1;
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};