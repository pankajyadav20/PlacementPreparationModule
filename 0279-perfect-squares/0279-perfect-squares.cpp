class Solution {
public:
      int fun(int ind, int cap, vector<int>& arr , vector<vector<int>> &dp){
        if(ind == 0){
            if((cap % arr[ind]) == 0)  
                return cap / arr[ind];
            else return 1e9;
        } 
        if(dp[ind][cap] != -1){
            return dp[ind][cap];
        }
        int take = INT_MAX;
            if(arr[ind] <= cap)
             take = 1 + fun(ind, cap - arr[ind] ,arr , dp);
         int notTake =  fun(ind - 1 , cap , arr , dp);
        return dp[ind][cap] = min(take , notTake);

    }
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1 ; i * i <= n ;i++){
            squares.push_back(i*i);
        }
        vector<vector<int>> dp(squares.size() , vector<int>(n + 1 , -1));
    
        return fun(squares.size() - 1, n , squares ,dp);    
        
    }
};







