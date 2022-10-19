
class Solution {
public:
	string frequencySort(string s) {

		unordered_map<char,int> mp;

		for(auto it : s){
			mp[it]++;
		}

		priority_queue<pair<int,char>> pq;

		for(auto it : mp){
			pair<int, char> p;
			p.first = it.second;
			p.second = it.first;
			pq.push(p);
		}
		string ans;
		while(pq.size() != 0){
			int k = pq.top().first;
			while(k--){
				ans += pq.top().second;
			}
			pq.pop();
		}
		return ans;
	}
};