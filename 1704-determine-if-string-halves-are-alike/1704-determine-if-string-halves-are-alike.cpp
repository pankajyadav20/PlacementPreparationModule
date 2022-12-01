class Solution {
public:
   bool isVowel(char s) {
       if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
           return true;
       } 
       if(s == 'A' || s ==  'E' || s ==  'I' || s ==  'O' || s == 'U')
       return true;
       return false;
   }
    bool halvesAreAlike(string s) {
            
        int cnt1 = 0 , cnt2 = 0 , n = s.size();
        for(int i = 0 ; i < s.size() / 2 ; i++){
                if(isVowel(s[i])){
                    cnt1++;
                }
                if(isVowel(s[n/2 + i])){
                    cnt2++;
                }
        }
        return cnt1 == cnt2;
    }
};