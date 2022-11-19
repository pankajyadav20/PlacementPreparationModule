class Solution {
public:
    void fun(int idx , vector<int> &temp , vector<int> &nums , vector<vector<int>> &ans){
        if(idx < 0){
            ans.push_back(temp);
            return;
        }
        
        // take 
        temp.push_back(nums[idx]);
         fun(idx - 1 , temp , nums , ans);
        temp.pop_back();
        // not take
        fun(idx - 1,  temp ,nums , ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(nums.size() - 1, temp , nums , ans);
        return ans;
    }
};