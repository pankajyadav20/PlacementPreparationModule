class Solution {
public:
    bool squareIsWhite(string coordinates) {
            int a=coordinates[0]+coordinates[1];
        if(a%2==1)
        return true;
        return false;
    }
};