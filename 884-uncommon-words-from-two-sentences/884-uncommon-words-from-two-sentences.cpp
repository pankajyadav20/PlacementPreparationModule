
class Solution {
public:
    vector<string> uncommonFromSentences(string str1, string str2) {
        unordered_map<string ,int> mp;
        vector<string> s1 , s2;
        string temp1 = "" , temp2  = "";
        for(int i = 0 ; i < str1.size() ; i++){

        	 // temp1 += str1[i];
        	if(i == str1.size() - 1){
        		temp1 += str1[i];
        			s1.push_back(temp1);
        	}
        	 if(str1[i] == ' '){
        	 		s1.push_back(temp1);
        	 		temp1 = "";
        	 }else temp1 += str1[i];

        }
        for(int i = 0 ; i < str2.size() ; i++){

        	 // temp1 += str1[i];
        	if(i == str2.size() - 1){
        		temp2 += str2[i];
        			s2.push_back(temp2);
        	}
        	 if(str2[i] == ' '){
        	 		s2.push_back(temp2);
        	 		temp2 = "";
        	 }else temp2 += str2[i];

        }
        for(auto it : s1){
        	mp[it]++;
        }
        for(auto it : s2){
        	mp[it]++;
        }
        vector<string> ans;
        for(auto it : mp){
        	if(it.second == 1){
        		ans.push_back(it.first);
        	}
        }
        return ans;
    }
};