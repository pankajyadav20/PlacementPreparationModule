//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int fun(long long int idx , int coins[] ,long long int sum ,      vector<vector<long long int>> &dp){
      if(sum < 0 ) return 0;
      if(sum == 0){
          return 1;
      }
      if(idx == 0){
          if(sum % coins[idx] == 0){
              return 1;
          }
          return 0;
      }
      if(dp[idx][sum] != -1){
          return dp[idx][sum];
      }
      long long int notTake = 0 + fun(idx - 1, coins , sum , dp);
      long long int take =  fun(idx , coins , sum - coins[idx] , dp);

      return dp[idx][sum] = take +  notTake;
      
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N, vector<long
        long int>(sum + 1, -1));
        
        return fun(N-1, coins , sum , dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends