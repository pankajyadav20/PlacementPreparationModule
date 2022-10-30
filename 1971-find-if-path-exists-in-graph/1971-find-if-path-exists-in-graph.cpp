class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        
        vector<int> adj[n+1];
        
        for(int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0] , b = edges[i][1];  
            adj[a].push_back(b);   adj[b].push_back(a);
        }
    //     for (int v = 0; v < n; ++v) {
    //     cout << "\n Adjacency list of vertex " << v
    //          << "\n head ";
    //     for (auto x : adj[v])
    //         cout << "-> " << x;
    //     printf("\n");
    // }
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int front = q.front();  q.pop();
            for(auto it : adj[front]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return vis[des];
    }
};