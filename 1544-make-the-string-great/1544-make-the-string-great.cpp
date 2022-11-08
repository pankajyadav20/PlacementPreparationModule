class Solution {
public:
    string makeGood(string s) {
        
        stack<char> st;
        for(int i = 0; i < s.size();  i++){
            
            if(st.empty()){
                st.push(s[i]);
            }
            else
            if(st.top() == toupper(s[i]) && islower(s[i])){   //    Ee
                
                if(!st.empty()){
                    st.pop();
                }
                
            }else if(st.top() == tolower(s[i]) && isupper(s[i])){  // eE
                if(!st.empty()){
                    st.pop();
                }
            } else st.push(s[i]);
            
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};