class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int ans = 0;
        unordered_map<string , int> mp;
        
        for(int i = 0 ; i < words.size() ;i++){
            mp[words[i]]++;
        }
        bool flag = 0;
        for(int i = 0 ;i < words.size() ; i++){
            string cur = words[i];
            string rev = "";
            rev += cur[1];
            rev += cur[0];
            if(rev == cur){
                
                if(mp[rev] > 0 ){
                if(mp[rev] & 1){
                    ans += 2 * (mp[rev] - 1);
                    flag = 1;
                }else ans += 2 * mp[rev];
                      mp[rev] = 0;
                }
            }else {
                if(mp[cur] > 0){
                    ans += min( 4 * mp[rev] , 4 * mp[cur]);
                    mp[rev] = 0;
                    mp[cur] = 0;
                }
            }
            
        }
        if(flag) 
            ans+=2;
        return ans;
    }
};