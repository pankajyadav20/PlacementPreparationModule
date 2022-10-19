
class Solution {
public:
    static bool cmp(pair<int,string> i, pair<int,string> j){
        if(i.first!=j.first)
            return i.first>j.first;
        else
        {
            return i.second<j.second;
        }
    }
	vector<string> topKFrequent(vector<string>& words, int k) {


		unordered_map<string, int> mp;
		for (auto it : words) {
			mp[it]++;
        }
        vector<string> ans;       
        deque<pair<int,string>> dq;  
        for(auto it : mp)
            dq.push_back({it.second,it.first});

        sort(dq.begin() , dq.end() , cmp);
		while(k--){
            string s = dq.front().second;
            dq.pop_front();
            ans.push_back(s);
        }
        return ans;
	}
};
