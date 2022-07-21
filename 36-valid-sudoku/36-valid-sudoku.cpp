class Solution {
public:
    bool solveValid(int i, int j, vector<vector<char>> &board, char ch)
    {
        
        for(int k =0;k<9;k++)
        {
             if(board[i][k] == ch) return false;
            if(board[k][j] == ch ) return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==ch) return false;
        }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       
        
        for(int i=0;i<9;i++)
        {
             for(int j=0;j<9;j++)
             {
                 char ch = board[i][j];
                 if(ch !='.')
                 {
                      board[i][j]='.';
                      if(!solveValid(i,j,board,ch))
                          return false;
                     
                     board[i][j] = ch;
                 }
             }
        }
        return true;
    }
};