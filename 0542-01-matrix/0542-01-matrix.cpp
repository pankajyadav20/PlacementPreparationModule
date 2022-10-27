class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();   int m = mat[0].size();
        
        queue< pair< pair<int,int> , int> > q;
        vector<vector<bool>> vis(n , vector<bool>( m , 0));
        vector<vector<int>> ans( n ,  vector<int> ( m , 0));
        
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    q.push({{ i , j} , 0 });
                    vis[i][j] = 1; 
                }
            }
        }
        
        int dx[] = { -1, +1, 0, 0}; // up down left right
        int dy[] = {0, 0, +1, -1};

        while(!q.empty()){
                    
                int row = q.front().first.first;
                int col = q.front().first.second;
                int dis = q.front().second;
                q.pop();
                
                for(int k = 0 ; k < 4 ; k++){
                    
                    int i = row + dx[k];
                    int j = col + dy[k];
                    
                    if(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]){
                        q.push({{i, j} , dis+1});
                        ans[i][j] = dis + 1;
                        vis[i][j] = 1;
                    }
                    
                }
        }
        return ans;
    }
};










