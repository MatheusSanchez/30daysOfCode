/*

    Time complexity:(9^m) where,m is number of empty places
    Space complexity:O(1)

*/


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        couldSolve(0,0,board);
        
    }
    
    bool couldSolve(int row, int column, vector<vector<char>>& board){
        
        
      
        if(row == 9){
            return true;
        }else if(column == 9){
            return couldSolve(row+1,0,board);
        }
        
        
        if(board[row][column] == '.'){
          for(char i = '1'; i <= '9'; i++){
              
                if(isValidPlacement(board,row,column,i)){
                    board[row][column] = i;
                    if(couldSolve(row,column+1,board)){
                        return true;
                    }
                    board[row][column] = '.';
                }
            }
            return false;
        }else{
            return couldSolve(row,column+1,board);
        }
        
        return true;
        
    }
    
    bool isValidPlacement(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++)
            if(board[row][i] == c) return false;
        for(int i=0;i<9;i++)
            if(board[i][col] == c) return false;
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[row/3*3 + i][col/3*3 + j] == c)
                    return false;
        return true;
    }      
    

};