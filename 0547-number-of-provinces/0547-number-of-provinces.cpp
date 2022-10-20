class Solution {
public:
    void dfs(vector<bool> &visited , vector<int> adj[] , int node){
        
        visited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(visited , adj , it);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // creating adjacency list
        
        vector<int> adj[n+1];
        for(int i = 0 ; i < n  ;i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n); 
        int cnt = 0;
        for(int i = 0 ; i < n ;i++){
            
            if(!visited[i]){
                cnt++;
                dfs(visited, adj , i);
            }
            
        }
        return cnt;
    }
};