class Solution {
public:
    string reverseWords(string s) {
        
        int start , end , i  , j , len = 0 ;
        // removing multiple spaces from the begining
        for(i = 0 ;i < s.size() && s[i] == ' ' ; i++){
            
        }
        start = i;
        // removing multiple spaces from the end
        for(j = s.size() - 1 ; j >= 0 && s[j] == ' ' ; j--){
            
        }
        end = j;
        // removing multiple spaces between the string
        for(int k = start ; k <= end ; k++){
            if(s[k] == ' ' && s[k - 1 ] == ' '){
                continue;
            }
                 s[len] = s[k];
                 len++;
            
        }
        s.erase(s.begin() + len , s.end());
          reverse(s.begin(), s.end());
        for (i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        // last word
        reverse(s.begin() + start, s.end());
        return s;
    }
};









