class Solution {
public:
    int fun(int idx , int len , int n ){
        
        if(len == 0){
            return 1;
        }
        if(idx >= 5){
            return 0;
        }
        
        int notTake = fun(idx + 1 , len , n  );
        int take = fun( idx ,  len - 1 , n);
        
        return take + notTake;
        
    }
    int countVowelStrings(int n) {

        return fun(0 , n , n);
        
    }
};