
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>( m , 0));

        queue<pair<pair<int,int> , int>> q;

        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{ i , j} ,0});
                    vis[i][j] = 2;
                }
            }
        }
        
        int tm = 0;
        int dx[] = { -1, +1, 0, 0}; // up down left right
        int dy[] = {0, 0, +1, -1};   
        int maxi = 0;
        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxi = max(maxi ,time);
            q.pop();
            for(int k = 0 ; k  < 4 ; k++){
                int i = row + dx[k];
                int j = col + dy[k];

                if( i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0 && grid[i][j] == 1){
                    q.push({{i,j},time+1});
                    vis[i][j] = 2;
                }
            }

        }   
        // checking if all the oranges are rotten or not
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] != 1 && grid[i][j] == 1){
                    return -1;
                }
                // cout<<vis[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return maxi;
    }
};