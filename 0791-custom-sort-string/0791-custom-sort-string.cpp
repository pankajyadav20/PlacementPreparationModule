   map<char , int> prior;
    bool comp(char i, char j){
        if(prior[i] > prior[j]){
            return 1;
        }
        return 0;
    }
class Solution {
public:
 
    string customSortString(string order, string s) {
        int n = order.size();
        for(int i = 0 ; i < order.size() ; i++){
            prior[order[i]] = n;
            n--;
        }
        sort(s.begin(), s.end() , comp);
        return s;
    }
};