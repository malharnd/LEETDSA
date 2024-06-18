class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int x = matrix.size();
        int y = matrix[0].size();
        // vector<int> col(x,0);
        // vector<int> row(y,0);
        // use above to solve int Space(m+n)
        // matrix[i][0] == rows
        // matrix[0][...] == col but except j = 0 since overlaps
        
        int j0 = 1;
        
        for(int i = 0 ; i< x ; i++){
            for(int j = 0 ; j<y ; j++){
                if(matrix[i][j]==0 ){
                    matrix[i][0] = 0;
                    if(j!= 0){
                        matrix[0][j] = 0;
                    }
                    else{
                        j0 = 0;
                    }
                    
                }
            }
        }
        
        
        for(int i = 1 ; i< x ; i++){
            for(int j = 1 ; j<y ; j++){
                if(matrix[i][j]!= 0 ){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
                
                else{
                    continue;
                }
            }
        }
        
        if(matrix[0][0] == 0){
            for(int j = 0; j<y; j++) {
                matrix[0][j]=0;
            }
        }
        
        if(j0 == 0){
            for(int i = 0; i<x; i++){ 
                matrix[i][0]=0;
            }
            
        }
    }
};