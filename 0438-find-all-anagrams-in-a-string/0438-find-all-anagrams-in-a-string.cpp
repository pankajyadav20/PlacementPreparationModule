class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0 , j = 0 , n = s.size() , m = p.size();
        vector<int> temp1(26 , 0) , temp2(26 , 0) , ans;
        for(int i = 0 ;i < m ; i++)
            temp1[p[i] - 'a']++;
        while(j < n){
            temp2[s[j] - 'a']++;
            if(j - i + 1 < m){
                j++;
            }else if(j - i + 1 == m){ 
                if(temp1 == temp2) {
                    ans.push_back(i);
                }   
                // slide the window
                temp2[s[i] - 'a']--;
                i++;
                j++;
            }   
        }
        return ans;
    }
};

