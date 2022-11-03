class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char , int > mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        int ans = 0;
        bool flag = 0;
        for(auto it : mp){
            if(it.second & 1){
                ans += it.second - 1;
                flag = 1;
            }else ans += it.second;
        }
        if(flag) ans++;
        return ans;
    }
};