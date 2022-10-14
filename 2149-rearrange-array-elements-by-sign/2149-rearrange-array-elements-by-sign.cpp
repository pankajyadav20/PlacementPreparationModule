class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =  nums.size() , k = 0;
        vector<int> ans(n);
        int posi = -1 , neg = -1;
       for(int i = 0 ; i < nums.size() ; i++){
           if(nums[i] > 0 && posi == -1){
               posi = i;
           }else if(nums[i] < 0 && neg == -1){
               neg = i;
           }
       }
            
        while(posi < n && neg < n){
            while(nums[posi] < 0){
                posi++;
            }
            ans[k++] = nums[posi++];
            while(nums[neg] > 0){
                neg++;
            }
            ans[k++] = nums[neg++];
        }
        return ans;
    }
};