class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i1 = -1 ,  i2 = -1, n = nums.size();
        if(n == 1 ){
            return ;
        }
        
        for(int i = n - 2; i >= 0  ; i--){
            if(nums[i] < nums[i + 1]){
                i1 = i;
                break;
            }
        }
        if(i1 == -1){
            reverse(nums.begin() , nums.end());
            return;
        }
              
        for(int i = n - 1; i >= 0  ; i--){
            if(nums[i] > nums[i1]){
                i2 = i;
                break;
            }
        }
        // cout<<i1<<" "<<i2<<endl;
        swap(nums[i1] , nums[i2]);
        reverse(nums.begin() + i1 + 1, nums.end());
        
    }
};