//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n  = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , 0));
        queue< pair< pair<int,int> ,int >> q; 
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 2 ){
                    vis[i][j] = 2;
                    q.push( { { i , j } , 0});
                }
                
            }
        }
        
        int maxi = 0;
        
        int dx[] = { -1, +1, 0, 0}; // up down left right
    	int dy[] = {0, 0, +1, -1};

        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            maxi = max(maxi , time);
            
            for(int k = 0 ; k < 4 ; k++){
                int i = row + dx[k];
                int j = col + dy[k];
                  if( i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0 && grid[i][j] == 1){
                    q.push({{i,j},time+1});
                    vis[i][j] = 2;
                }
            }
        }
          for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] != 1 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return maxi;
    }
};










//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends