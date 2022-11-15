class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int i = 0 , j = 0 , n = s1.size() , m = s2.size();
        vector<int> temp1(26 , 0) , temp2(26 , 0);
        for(int i = 0 ;i < n ; i++){
            temp1[s1[i] - 'a']++;
        }
        
        while(j < m ){
            temp2[s2[j]-'a']++;
            if(j - i + 1 < n){
                j++;
            }else if(j - i + 1 == n ){
                
                   if( temp2 == temp1 )
                       return 1;
                   
                //slide the window
                temp2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return 0;
    }
};