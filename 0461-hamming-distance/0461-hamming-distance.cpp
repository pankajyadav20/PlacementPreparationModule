class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int cnt = 0;
        
        while( x > 0 || y > 0){
            int temp1 = x % 2 , temp2 = y % 2;
            if(temp1 != temp2){
                cnt++;
            }
            x = x / 2; y = y / 2;
        }
        return cnt;
    }
};