class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char , int> fuck;
         fuck['b'] = 0; fuck['a'] = 0; fuck['l'] = 0; fuck['o'] = 0; fuck['n'] = 0;
        for(auto it : text){
            fuck[it]++;
        }
//         balloon     b->1 , a -> 1 , l -> 2, o -> 2 , n -> 1
        int cnt = 0 , mini = INT_MAX;
        for(auto dick : fuck){
            
            if(dick.first == 'b' || dick.first == 'a' || dick.first == 'n'){
                mini = min(mini , dick.second);
            }else if(dick.first == 'o' || dick.first == 'l'){
                mini = min(mini,  dick.second/2);
            }
        }
        return mini;
    }
};