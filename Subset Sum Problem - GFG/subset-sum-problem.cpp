//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
    
    private:
    bool fun(vector<int> arr , int idx , int k , vector<vector<int>> &dp){
        if(idx == 0){
            return arr[idx] == k;
        }
        if(k < 0){
            return 0;
        }
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }
        int notTake = fun(arr ,idx - 1, k , dp);
        int take = fun(arr , idx - 1 , k - arr[idx] , dp);
        return dp[idx][k] = notTake || take;
        
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size() , vector<int>(sum+1,-1));
        return fun(arr , arr.size() -1 , sum , dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends