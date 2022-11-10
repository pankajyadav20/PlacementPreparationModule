class Solution {
public:
    string removeStars(string s) {
        int cnt = 0;
          for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '*'){
                cnt++;
            }
        }
        if(cnt == 0){
            return s;
        }
        
        stack<char> st;
        for(int i = 0 ; i < s.size() ; i++){
            if(!st.empty() && s[i] == '*'){
                st.pop();
            }else st.push(s[i]);
            
        }
        string ans = "";
        
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};