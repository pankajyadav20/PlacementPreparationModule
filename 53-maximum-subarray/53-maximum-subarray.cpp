class Solution {
public:
    int maxSubArray(vector<int>& arr) {
       int curSum = 0;
        int maxi = INT_MIN;
        
        for(int i = 0 ; i < arr.size() ; i++){
            curSum+=arr[i];
            if(curSum >  maxi)
            maxi = curSum;
            if(curSum < 0)
            curSum = 0;
        }
        return maxi;
    }
};