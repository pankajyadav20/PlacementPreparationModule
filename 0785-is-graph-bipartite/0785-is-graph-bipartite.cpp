class Solution {
public:
    bool bfs( vector<vector<int>>& graph ,  int src , vector<int> &vec){
         int n = graph.size();
        
        // vector<int> vec(n,  -1);     // -1 -> no color
        queue<int>  q;
        q.push(src);
        vec[src] = 1;
        while(!q.empty()){
         
            int node = q.front(); q.pop();
            
            for(auto it : graph[node]){
                
                if(vec[it] == -1){
                    vec[it] = 1 - vec[node];
                    q.push(it);
                }else  if(vec[it] == vec[node]){
                            return false;
                           
                }
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> vec(n,  -1);     // -1 -> no color
        
           for(int i=0;i<n;i++){
            if(vec[i]==-1){
                if(!bfs(graph,i ,vec))return false;
            }
        }
        
        return true;
    }
};