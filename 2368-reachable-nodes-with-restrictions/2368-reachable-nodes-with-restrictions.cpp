class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        
        
        unordered_map<int,bool> mp;
        for(auto it : res){
            mp[it] = 1;
        }
        
        vector<int> adj[n+1];
        for(int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0] , b = edges[i][1];
            adj[a].push_back(b);  adj[b].push_back(a);
        }
    //      for (int v = 0; v < n; ++v) {
    //     cout << "\n Adjacency list of vertex " << v
    //          << "\n head ";
    //     for (auto x : adj[v])
    //         cout << "-> " << x;
    //     printf("\n");
    // }
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int ans = 0;
        while(!q.empty()){
            int node = q.front();   q.pop();
            
            if(mp.find(node) != mp.end()){
                continue;
            }
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
            ans++;
        }
        return ans; 
    }
};