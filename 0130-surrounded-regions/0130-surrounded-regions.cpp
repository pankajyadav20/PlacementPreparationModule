class Solution {
     bool isBorder(int i, int j, int m, int n){
        return (i==0 || i==m-1 || j==0 || j==n-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size() ;  int m = board[0].size();
        
        vector<vector<bool>> vis(n , vector<bool>(m , 0));
        // vector<vector<char>> ans(n , vector<char>(m , 'O'));
        
        queue<pair<int,int>> q;
        
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && isBorder(i,j,n,m)){
					q.push(make_pair(i,j));  
                    vis[i][j] = 1;
                }
            }
        }
        
      
        int dx[] = { -1, +1, 0, 0}; // up down left right
        int dy[] = {0, 0, +1, -1};

        while(!q.empty()){      
                int row = q.front().first;
                int col = q.front().second;
                q.pop();    
                // cout<<"hi"<<endl;
                for(int  k  = 0 ; k < 4 ; k++){
                        
                        int i = row + dx[k];
                        int j = col + dy[k];
                    
                    if(i >= 0 && i < n  && j >= 0 && j < m && !vis[i][j] && board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] = 1;
                        // cout<<"hi"<<endl;
                    }
                    
                }
        }
        for(int i = 0 ; i <  n ; i++){
            for(int j =  0 ; j < m ; j++){
                        if(!vis[i][j] && board[i][j] == 'O'){
                            board[i][j] = 'X';
                        }   
                // cout<<vis[i][j]<<" ";
            }
            // cout<<endl;
        }
       
        // board = ans;
        
    }
};





