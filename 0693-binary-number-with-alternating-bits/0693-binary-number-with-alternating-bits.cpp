class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int num = n;
        int cur = num % 2;
        num = num / 2;
        while(num > 0){
                if(cur == num % 2){
                    return false;
                }
            cur = num % 2;
                num = num / 2;
            
        }
        return true;
    }
};