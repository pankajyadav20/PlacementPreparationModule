class Solution {
public:
    
    void dfs(int src , int dest , vector<vector<int>> &graph , 
             vector<int> &temp , vector<vector<int>> &ans){
        temp.push_back(src);
        if(src == dest){
             ans.push_back(temp);
        }
    
       else{
           for(auto it : graph[src]){
               dfs(it , dest , graph , temp , ans);
           }
       }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        int src = 0 , dest = graph.size() - 1;
        vector<int> temp;
        dfs(src , dest , graph , temp ,ans);
        return ans;
    }
};