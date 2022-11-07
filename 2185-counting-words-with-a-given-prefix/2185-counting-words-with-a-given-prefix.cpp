class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int cnt = 0;
        
        for(int i = 0; i  < words.size() ; i++){
                
                string str = "";
                
                for(auto it : words[i]){
                    str += it;
                    if(str == pref){
                        cnt++;
                        break;
                    }
                }
            
        }
        return cnt;
    }
};