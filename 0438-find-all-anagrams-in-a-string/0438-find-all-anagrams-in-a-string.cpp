class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> temp1(26 , 0) , temp2(26 , 0);
        for(int i = 0 ;i <  p.size() ; i++){
            temp1[p[i] - 'a']++;
        }
        
        int i = 0 , j = 0 , n = s.size() , m = p.size() , cnt = 0;
        vector<int> ans;
        
        while(j < n){
            temp2[s[j] - 'a']++;
            if(j - i + 1 < m){
                j++;
            }else if(j - i + 1 == m){
                  
                bool flag = 1;
                for(int i = 0 ;i < 26 ; i++){
                    if(temp1[i] != temp2[i]){
                        flag = 0;
                    }
                }
                if(flag) {
                    ans.push_back(i);
                    // cnt++;
                }
                
                // slide the window
                temp2[s[i] - 'a']--;
                i++;
                j++;
            }
        }
        // cout<<cnt<<endl;
        return ans;
    }
};

