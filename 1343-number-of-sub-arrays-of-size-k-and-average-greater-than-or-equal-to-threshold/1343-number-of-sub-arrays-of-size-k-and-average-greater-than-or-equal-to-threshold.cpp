class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
            
        int cnt = 0 , i = 0 , j = 0 , sum = 0 , n = arr.size();
        
        while(j < n){
                
            sum += arr[j];
            
            if(j - i + 1 < k){
                j++;
            }else{
                if ( (sum / k)  >= threshold){
                    cnt++;
                }  
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return cnt;
    }
};