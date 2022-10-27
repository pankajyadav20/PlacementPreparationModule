class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();  int m = grid[0].size();
        
        vector<vector<bool>> vis(n , vector<bool>(m , 0));
        
        queue<pair<int,int>>  q;
        
        
        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < m ; j++){
                    
                if(grid[i][j] == 1){
                    
                    if(i == 0 || j == 0|| i == n -1 || j == m -1){
                        q.push({i,j});
                        vis[i][j] = 1;
                        // cout<<i<<" "<<j<<endl;
                    }       
                }
            }
        }
            
        int dx[] = { -1, +1, 0, 0}; // up down left right
        int dy[] = {0, 0, +1, -1};

        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k = 0 ; k < 4 ; k++){
                    
                int i = row + dx[k];  int j = col + dy[k];
                
                if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] =  1;
                }   
            }
        }
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};






