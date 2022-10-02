
class Solution {
public:
    const int mod = 1000000007;
	int fun(int idx , int target , int faces , vector<vector<int>> &dp){
		if(target < 0){
			return 0;
		}
		if(idx == 0 && target != 0 || idx != 0 && target == 0){
			return 0;
		}

		if(idx == 0 && target == 0){
			return 1;
		}
		if(dp[idx][target] != -1){
			return dp[idx][target]; 
		}
		int ans = 0;
		for(int i = 1 ; i <= faces ; i++){
			ans = ( ans % mod +   fun(idx - 1 , target - i , faces , dp) % mod ) % mod;
		}
		return dp[idx][target] = ans;
	}
    int numRollsToTarget(int n, int k, int target) {
    	vector<vector<int>> dp(n + 1, vector<int>( target + 1 , -1));
        return fun( n , target , k , dp);
    }
};