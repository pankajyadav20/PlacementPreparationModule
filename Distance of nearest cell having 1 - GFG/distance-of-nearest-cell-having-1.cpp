//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    
	    int n = grid.size();   int m = grid[0].size();
	    vector<vector<bool>> vis(n , vector<bool>(m ,0));
	    vector<vector<int>> ans(n , vector<int>(m ,0));
	    queue< pair< pair<int,int> , int>> q;
	    
	    for(int i = 0 ; i < n ; i++){
	        for(int j =  0 ; j  < m ;  j++){
	                if(grid[i][j] == 1){
	                    q.push({{i ,j } , 0});
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
	                int i = row + dx[k];   int j = col + dy[k];
	             if(i >= 0 && i < n && j >= 0 && j < m &&!vis[i][j]
	             && grid[i][j] == 0){
	                    vis[i][j] = 1;
	                    q.push({{i,j} , dis +1});
	                    ans[i][j] = dis + 1;
	                }
	            }
        }
        return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends