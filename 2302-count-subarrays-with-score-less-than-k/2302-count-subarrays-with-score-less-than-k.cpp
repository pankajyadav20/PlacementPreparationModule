typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        ll i = 0 , j = 0 , ans = 0 , n = nums.size();
        ll score = 1 , sum = 0;
        
        while(j < n){
            sum += nums[j];
            score = sum * (j - i + 1);
            if(score < k){
                ans += j - i + 1;
                j++;
            }else if(score >= k){
                
                while(score >= k){
                    sum -= nums[i];  
                      i++;
                    score = sum * (j - i + 1);
                    // cout<<score<<endl;
                }
                ans += j - i + 1;
                j++;
            }
            
        }
        
        return ans;
    }
};