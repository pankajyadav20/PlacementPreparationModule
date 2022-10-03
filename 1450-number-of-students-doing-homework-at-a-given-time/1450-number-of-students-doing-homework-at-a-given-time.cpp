class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int qt) {
        int ans = 0;
        for(int i = 0  ; i < startTime.size();  i++){
            if(startTime[i] <= qt && qt <= endTime[i]){
                ans++;
            }
        }
        return ans;
    }
};