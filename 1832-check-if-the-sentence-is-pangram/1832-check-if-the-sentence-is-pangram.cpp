class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> v(26 , 0);
        for(int i = 0; i < s.size() ; i++){
            v[s[i] - 'a']++;
        }
        for(auto it : v){
            if(it == 0){
                return 0;
            }
        }
        return 1;
    }
};