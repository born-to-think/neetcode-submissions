class Solution {
public:
    int m,n;
    bool dfs(int i, int j,vector<vector<char>>& board){
        if(i<0 || j<0|| i>=m || j>=n)return false;
        if(board[i][j]=='V' || board[i][j]=='X')return true;

        board[i][j]='V';
        if(
            dfs(i  ,j-1,board) &&
            dfs(i-1,j  ,board) &&
            dfs(i  ,j+1,board) &&
            dfs(i+1,j  ,board) 
        ){
            board[i][j] = 'X';
            return true;
        }
        else return false;

    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n=board[0].size();
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='O') dfs(i,j,board);
            }
        }
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'V')board[i][j]='O';
            }
        }
    }
};
