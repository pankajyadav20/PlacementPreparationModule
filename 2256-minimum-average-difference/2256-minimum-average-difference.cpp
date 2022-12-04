class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
 int n=nums.size();
    long long int right=accumulate(nums.begin(),nums.end(),0ll);
    long long int left=0;
    long long int ans=0;
    long long int max=INT_MAX;
    for(int i=0; i<n-1; i++){
        left+=nums[i];
        long long int x=left/(i+1);
        long long int y=right-left;
        y=y/(n-i-1);
        long long int j=abs(x-y);
        if(max>abs(y-x)){
             max=j;
            ans=i;
        }
    }
    if(max>(left+nums[n-1])/n){
        ans=n-1;
    }
    return ans;
    }
};