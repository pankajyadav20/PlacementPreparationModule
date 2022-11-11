class Solution {
public:
      
    void fun(int open , int close , string str , vector<string> &ans){
        
        if(open == 0 && close == 0){
            ans.push_back(str);
            str = "";
            return;
        }
        if(open < 0 || close < 0){
            return ;
        }
        if(close < open){
            return;
        }
        string temp1 = str + '(' , temp2 = str + ')';
        fun(open - 1 , close , temp1 , ans);
        fun(open , close - 1, temp2 , ans);
        
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        fun( n , n , "" , ans);
        return ans;
    }
};