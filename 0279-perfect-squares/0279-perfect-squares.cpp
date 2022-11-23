class Solution {
public:
    int fun(int idx , int cap, vector<int> &arr , vector<vector<int>> &dp){
        if(idx == 0){
            if(cap % arr[idx] == 0)  
                return cap / arr[idx];
            else return 1e9;
        } 
        if(dp[idx][cap] != -1){
            return dp[idx][cap];
        }
        int notTake = 0 + fun(idx - 1 , cap , arr , dp);
        int take = 1e9 ;
            if(arr[idx] <= cap){
             take = 1 + fun(idx, cap - arr[idx] ,arr , dp);
            }
        return dp[idx][cap] = min(take , notTake);

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







