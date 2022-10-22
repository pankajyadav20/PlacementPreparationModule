class Solution {
public:
    string generateTheString(int n) {
        
        string ans = "";
        
        if ( !(n & 1) ){
                
            ans += 'a';
            n--;
            while(n--){
                ans += 'b';
            }
            
        }else{
            while(n--){
                ans += 'a';
            }
        }
        return ans;
    }
};