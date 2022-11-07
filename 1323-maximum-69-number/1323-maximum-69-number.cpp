class Solution {
public:
    int maximum69Number (int num) {
        
//         int ans = 0;
        
//         while(num!=0){
//             int dig = num % 10;
//             num /= 10;
            
//         }
        string str = "";
        str = to_string(num);
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == '6'){
                str[i] = '9';
                break;
            }
        }
        int ans = stoi(str);
        return ans;
    }
};