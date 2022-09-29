class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>  ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0 ; i < arr.size() ; i++){
            int diff = abs(x - arr[i]);
            pq.push({diff , arr[i]});
        }
        vector<int> ans;
        while(k--){
                pair<int,int> p = pq.top();
                pq.pop();
            ans.push_back(p.second);
        }
    sort(ans.begin()  , ans.end());
        return ans;
    }
};