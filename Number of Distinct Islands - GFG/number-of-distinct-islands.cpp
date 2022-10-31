//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i , int j , vector<vector<int>> &grid ,   vector<pair<int,int>> &vec, 
    vector<vector<bool>> &vis , int iBase , int jBase){
            int n = grid.size() , m =  grid[0].size();
        
        vis[i][j] = 1;
        vec.push_back( { i - iBase ,  j - jBase });
        int dx[] = { -1, +1, 0, 0}; // up down left right
    	int dy[] = {0, 0, +1, -1};

        for(int k = 0 ; k < 4 ; k++){
            
            int row = i + dx[k];  int col = j + dy[k];
            if(row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && grid[row][col] == 1){
                
                dfs(row , col , grid , vec , vis , iBase , jBase);
                
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() , m =  grid[0].size();
        set<vector< pair<int,int> >> st;
        vector<vector<bool>> vis(n , vector<bool>(m , 0 ));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 1 && !vis[i][j]){
                    
                    vector<pair<int,int>> vec;
                    dfs( i , j , grid ,vec , vis , i , j);
                    st.insert(vec);
                    
                }
                
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends