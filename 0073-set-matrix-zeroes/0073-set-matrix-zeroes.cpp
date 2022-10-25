class Solution {
    private:    
    void fun( vector<vector<int>> &mat , int i , int j , int n , int m){
            
        for(int i = 0 ; i < m ;i++){
             if(mat[i][j] != 0){
            mat[i][j] = INT_MIN;
            }
        }
        for(int j = 0 ;j < n ; j++){
            if(mat[i][j] != 0){
            mat[i][j] = INT_MIN;
            }
        }
        
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> matrix2(m , vector<int>(n));
        
          for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                matrix2[i][j] = matrix[i][j];
            }
        }
        
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    
                           for(int k = 0 ;k < n ;k++)
                                matrix2[i][k] = 0;

                            for(int k = 0 ;k < m ; k++)
                                matrix2[k][j] = 0;
                }
            }
        }
             for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                matrix[i][j] = matrix2[i][j];
            }
        }


    }
};