class Solution {
public:
    double average(vector<int>& s) {
        
        double mini = s[0] , maxi = s[0] , sum = 0;
        for(auto it : s){
            if( it > maxi){
                maxi = it;
            }
            if(it < mini){
                mini = it;
            }
            sum += it;
        }
        return (sum - mini - maxi) / (s.size()- 2); 
    }
};