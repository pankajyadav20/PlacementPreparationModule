class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<int,int> mp;
        int i = 0 , j = 0 , n = s.size() , ans = 0;
        
        while(j < n){
            mp[s[j]]++;
            
            if(mp.size() == j - i + 1){
                ans = max(ans , j - i + 1);
                j++;
            }else if(mp.size() < j - i + 1){
                    
                while(mp.size() < j - i + 1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                ans = max(ans , j - i + 1);
                j++;
            }
        }
        return ans;
    }
};