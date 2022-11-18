class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i = 0 , j = 0 , n = nums.size();
        deque<int> li;
        vector<int> ans;
        
        while(j < n ){
            // removing all the elements that area redundant i.e not less than my cur element 
            while(!li.empty() && li.back() < nums[j]){
                li.pop_back();
            }
             li.push_back(nums[j]);
              
            if(j - i  + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                ans.push_back(li.front());
                // remove the calculations
               if(li.front() == nums[i]){
                   li.pop_front();
                }    
                //slide the window
                i++;
                j++;
            }
        }
        
        return ans;
    }
};