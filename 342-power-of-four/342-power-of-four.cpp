class Solution {
public:
    bool isPowerOfFour(int n) {
        
        while(n % 4 == 0 && n  > 0){
            n = n / 4;
        }
        if(n == 1){
            return 1;
        }else return 0;
    }
};