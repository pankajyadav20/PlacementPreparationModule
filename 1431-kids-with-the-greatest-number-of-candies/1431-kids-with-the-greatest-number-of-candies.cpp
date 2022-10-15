class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        int maxi = 0;
        for(auto it : candies){
            maxi = max(maxi , it);
        }
        vector<bool> ans(candies.size());
        for(int i = 0 ; i < candies.size() ; i++){
            if(candies[i] + e >= maxi){
                ans[i] = 1;
            }else ans[i] = 0;
        }
        return ans;
    }
};