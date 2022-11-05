class Solution {
public:
    int arrangeCoins(int n) {
        
        for(int i = 1 ; i <= n ; i++){
                  n -= i;
            if(n <= i){
                return i;
            }
            // cout<<n<<" "<<i<<endl;
        }return 0;
    }
};