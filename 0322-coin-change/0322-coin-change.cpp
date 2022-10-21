class Solution {
public:
    int fun(vector<int>& arr, int ind, int T, vector<vector<int>>& dp) {

	if (ind == 0) {
		if (T % arr[0] == 0) return T / arr[0];
		else return 1e9;
	}

	if (dp[ind][T] != -1)
		return dp[ind][T];

	int notTaken = 0 + fun(arr, ind - 1, T, dp);

	int taken = 1e9;
	if (arr[ind] <= T)
		taken = 1 + fun(arr, ind, T - arr[ind], dp);

	return dp[ind][T] = min(notTaken, taken);
}

    int coinChange(vector<int>& coins, int amount) {
            int x = amount , n = coins.size();
        	vector<vector<int>> dp(n, vector<int>(x + 1, -1));
	        int ans =  fun(coins, n - 1, x, dp);
        if(ans >= 1e9){
            return -1;
        }else return ans;
    }
};