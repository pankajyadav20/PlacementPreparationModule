//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<vector<int>> &grid , int i , int j , int color , int newColor ,
    vector<vector<bool>> &vis){
        vis[i][j] = 1;
        
         int n = grid.size();
        int m = grid[0].size();
        
        int dx[] = { -1, +1, 0, 0}; // up down left right
        int dy[] = {0, 0, +1, -1};
        
        for(int k = 0 ;k < 4 ; k++){
            
            int row = i + dx[k];
            int col = j + dy[k];
            
            if(row >= 0 && row < n
            && col >= 0 && col < m
            && grid[row][col] == color
            && !vis[row][col]){
                grid[row][col] = newColor;
                dfs(grid , row , col, color , newColor, vis);
            }
            
        }
        
    }
    public: 
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>( m, 0));
        int initialColor = grid[sr][sc];
        grid[sr][sc] = newColor;
        dfs(grid,sr,sc,initialColor , newColor , vis);
        return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends