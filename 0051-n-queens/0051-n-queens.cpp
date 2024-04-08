class Solution {
private:

bool isSafe(int row, int col, int n, vector<vector<int>> &board ){
    int x = row;
    int y = col;
    
    // check for row i.e y decrease
    while(y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        else{
            y -- ;
        }
    }
    
    x = row;
    y =col;
    
    while(x>= 0 && y>= 0){
        if(board[x][y] == 1){
            return false;
        }
        else{
            x --;
            y -- ;
        }
    }
    
    x = row;
    y =col;
    
    while(x < n && y>= 0){
        if(board[x][y] == 1){
            return false;
        }
        else{
            x ++;
            y -- ;
        }
    }
    
    return true;
}

void addsolution (vector<vector<string>> &ans,vector<vector<int>> &board, int n){
    vector<string> temp;

    for(int i = 0; i<n ; i++){
        string s;
        for(int j = 0; j<n ; j++){
            if(board[i][j] == 1){
                s.push_back('Q');
            }

            else{
                s.push_back('.');
            }
        }
        temp.push_back(s);
    }

    ans.push_back(temp);
}

void solve(int col, int n , vector<vector<string>> &ans,vector<vector<int>> &board){
    
    // base case
    if(col == n){
        addsolution(ans,board,n);
        return;
    }
    
    for(int row = 0; row<n; row++){
        if(isSafe(row,col,n,board)){
            board[row][col] = 1;
            solve(col+1 ,n , ans, board);
            board[row][col] = 0;
        }
    }
}

    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>>board(n,vector<int> (n,0));
        solve(0 ,n , ans, board);
        return ans;
    }
};