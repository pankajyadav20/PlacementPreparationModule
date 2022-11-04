class Solution {
public:
       bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        
        int n = s.size();
        
        int low = 0 , high = n - 1; 
        
        while(low < high){
            
            while(low < n && !isVowel(s[low])){
                low++;
            }
            while(high >= 0 && !isVowel(s[high])){
                high--;
            }
            if(low < high){
                swap(s[low++] , s[high--]);
            }
        }
        return s;
    }
};