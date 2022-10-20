class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;  i < n ; i++){
            mp[nums[i]]++;
        }
        int cnt = 1 ,maxi = 0 ;
        for(int i = 0 ; i < n ; i++){
                cnt = 0;
            if(mp.find(nums[i] -1) == mp.end()){    // vo usme hai hi nahi
                
                int curNum = nums[i];
                
                while(mp.find(curNum) != mp.end()){
                    cnt++;
                    curNum++;
                }
            }
            maxi = max(cnt , maxi);
            
        }
        return maxi;
    }
};