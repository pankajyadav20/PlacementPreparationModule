class Solution {
public:
     // up down left right
    int dx[4] = { -1, +1, 0, 0};
    int dy[4] = {0, 0, +1, -1};
      
    bool isExit(int i , int j , int n , int m , vector<vector<char>>& maze , int startI , int startJ){
            if(i == startI && j == startJ){
                return false;
            }
            if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && ( maze[i][j] == '.') ){
                return true;
            }
        return false;
    }
    bool isValid(int i , int j , int n ,int m){
        if(i >= 0 && i < n && j >= 0 && j < m){
             return 1;    
        }
        return 0;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {       
        
            int n = maze.size() , m = maze[0].size();
            int startI = entrance[0] , startJ = entrance[1] ;
                    //{{row , col} , dis}
            queue< pair< pair<int,int> , int > > q;
            vector<vector<bool>> vis(n , vector<bool>(m , 0));    
            q.push({{startI , startJ} , 0});
        
        int ans = 0;
        while(!q.empty()){
                
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            if(isExit(row , col , n , m , maze ,startI , startJ )){
                return steps;
            }
                for(int k = 0 ; k < 4 ; k++){
                        int i = row + dx[k];
                        int j = col + dy[k];
                    if(isValid(i, j , n , m) && !vis[i][j] && maze[i][j] == '.'){
                        q.push({{i , j} , steps +  1});
                        vis[i][j] = 1;
                    }
                }
        }
        return -1;
    }
};












