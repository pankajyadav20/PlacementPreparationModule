class Solution {
public:
    int findClosestNumber(vector<int>& A) {
        int diff = INT_MAX, ans = INT_MAX;
        for (int n : A) {
            if (abs(n) < diff || (abs(n) == diff && n > ans)) {
                diff = abs(n);
                ans = n;
            } 
        }
        return ans;
    }
};