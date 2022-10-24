//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private :
    void dfs(vector<int> lis[] , int node , bool visited[]){
        
        visited[node] = 1;
        for(auto it : lis[node]){
            if(!visited[it]){
                dfs(lis , it , visited);
            }
        }
        
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        bool visited[V] = {0};
        vector<int> lis[V+1];
        
        for(int i = 0 ; i < adj.size() ; i++){
            for(int j = 0 ; j < adj.size() ; j++){
                if(adj[i][j] == 1 && i != j){
                    lis[i].push_back(j);
                    lis[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                cnt++;
                dfs( lis , i , visited);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends