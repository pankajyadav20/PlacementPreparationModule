class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto it : mp){
            pair<int,int> p;
            p.first = it.second;
            p.second = it.first;
            // cout<<it.first<<" "<<it.second<<endl;
            pq.push(p);
        }
        
        vector<int> ans;
        while(k-- && pq.size() != 0){
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};