class Solution {
public:

    bool check_cols(vector<vector<char>>& board){
        for(int col=0; col<9; col++){
            unordered_set<char> qq;
            for(int r = 0; r<9;r++){
                char curr = board[r][col];
                if(qq.count(curr) )return false;
                else qq.insert(curr);
            }
        }
        return true;
    }
    bool check_rows(vector<vector<char>>& board){
        for(int row=0; row<9; row++){
            unordered_set<char> qq;
            for(int c = 0; c<9;c++){
                char curr = board[row][c];
                if(qq.count(curr) )return false;
                else qq.insert(curr);
            }
        }
        return true;
    }
    bool check_sqrs(vector<vector<char>>& board){
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if(
            check_rows(board) && 
            check_cols(board) &&
            check_sqrs(board) ) return true;

        return false;
    }
};
