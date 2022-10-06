class Solution {
public:
    int minOperations(string s) {
        
        if(s.size() == 2){
            if(s[0] != s[1]){
                return 0;
            }
            return 1;
        }
        string str = "";
        for(int i = 0 ; i < s.size() ; i+=2){
            str += "01";  
        }
        
        int cnt = 0;
        for(int i = 0 ;i < s.size() ; i++){
                if(str[i] != s[i]){
                    cnt++;
                }
        }
       
        if( cnt < ( s.size() - cnt ) ){
            return cnt;
        }else return ( s.size() - cnt );
    }
};