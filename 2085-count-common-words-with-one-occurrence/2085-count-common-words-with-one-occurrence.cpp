class Solution {
public:
    int countWords(vector<string>& s1, vector<string>& s2) {
        
        unordered_map<string ,int> mp1  , mp2;
        
        for(auto it : s1){
        	mp1[it]++;
        }
        for(auto it : s2){
        	mp2[it]++;
        }
        int ans = 0;
        // vector<string> ans;
        for(auto it : mp1){
        	if(it.second == mp2[it.first] && it.second == 1){
        		ans ++;
        	}
        }
        return ans;
        
    }
};