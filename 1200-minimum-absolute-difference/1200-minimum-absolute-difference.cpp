class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int mini = INT_MAX;
        sort(arr.begin() , arr.end());
        for(int i = 1 ; i < arr.size(); i++){
            mini = min(mini,abs(arr[i] - arr[i-1]));
        }
        
        vector<vector<int>> ans;
        for(int i = 1 ; i < arr.size() ; i++){
            if((arr[i] - arr[i-1]) == mini){
                vector<int> temp;
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                ans.push_back(temp);
            }
        }
        // cout<<mini;
        return ans;
    }
};