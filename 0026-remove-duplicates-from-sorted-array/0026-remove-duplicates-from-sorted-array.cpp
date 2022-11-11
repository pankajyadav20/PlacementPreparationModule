class Solution {
public:
    int removeDuplicates(vector<int>& nums) {\
    
        int k = 0 , i = 0 , n = nums.size() ;
                                             
                                             
        while(i < n ){
            if(i < n - 1 && nums[i] == nums[i+1]){
                i++;
            }else  { 
                nums[k] = nums[i];
                k++;
                i++;
            }
        }
         return k;   
        
    }
};