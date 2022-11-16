//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int idx, int arr[] ,int target, int newSum , vector<vector<int>> &dp){
        if(target == newSum){
            return 1;
        }
        if(idx == 0){
            return newSum == target;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        int notTake = fun(idx -1 , arr , target , newSum ,dp);
        int take = 0;
        if(target >= newSum){
            take = fun(idx -1 , arr, target - arr[idx] , newSum + arr[idx] , dp);
        }
        return dp[idx][target] = take || notTake;
        
    }
    int equalPartition(int N, int arr[]){
        // code here
        int sum = accumulate(arr , arr + N , 0);
        vector<vector<int>> dp(N , vector<int>(sum + 1 , -1));
        return fun(N-1,arr , sum ,0 , dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends