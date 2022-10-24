class Solution {
    private :
    bool check( vector<vector<int>> mat , int i , int j){
        mat[i][j] = 0;
        for(int i = 0 ; i < mat.size() ; i++){
            if(mat[i][j] == 1){
                return 0;
            }
        }
        for(int j = 0 ; j < mat[0].size() ; j++){
            if(mat[i][j] == 1){
                return 0;
            }
        }
        return 1;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        
        for(int i = 0 ; i < mat.size() ; i++){
                for(int j = 0 ; j < mat[0].size() ; j++){
                                    
                        if(mat[i][j] == 1){
                            cnt += check( mat , i,  j);
                        }
                    
                }    
        }
        return cnt;
    }
};