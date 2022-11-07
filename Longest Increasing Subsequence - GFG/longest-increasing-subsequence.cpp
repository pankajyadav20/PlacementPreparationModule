//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int fun(int idx , int prevIdx , int a[] , int n ,  vector<vector<int>> &dp){
        
        if(idx == n - 1){
            if(a[idx] > a[prevIdx]){
                return 1;
            }
            return 0;
        }
        if(dp[idx][prevIdx + 1] != -1 ){
           return dp[idx][prevIdx + 1]; 
        }
        int notTake = 0 + fun(idx + 1, prevIdx , a , n , dp);
        int take = 0;
        if(prevIdx == -1 || a[idx] > a[prevIdx]){
            take = 1 + fun( idx + 1, idx , a , n , dp);
        }
        return dp[idx][prevIdx + 1] = max(notTake , take);
    }
    int longestSubsequence(int n, int a[]){
       // your code here
       vector<vector<int>> dp( n , vector<int>(n + 1 , -1));
       return fun(0 , -1 , a , n , dp);
    }
};



















//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends