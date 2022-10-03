class Solution {
public:
    int minCost(string c, vector<int >& nt) {
            
        
        int ans = 0 , i = 0 , j = 0 , n = nt.size();
        
        while(i < n && j < n){
            int maxi = 0 , curTotal = 0; 
            while( j < n && c[i] == c[j]){
                maxi = max(nt[j] , maxi);
                curTotal += nt[j];
                      j++;
            }
            i = j;
            ans += (curTotal - maxi);
        }
        return ans;
    }
};