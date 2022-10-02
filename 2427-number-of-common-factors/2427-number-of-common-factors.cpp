class Solution {
public:
    int commonFactors(int a, int b) {
        int n = __gcd(a , b);
        int res = 0;
        for(int i = 1 ; i <= sqrt(n) ; i++){
            if(n % i == 0){
                if(n / i  == i){
                    res += 1;
                }else res += 2;
            }
        }
        return res;
    }
};