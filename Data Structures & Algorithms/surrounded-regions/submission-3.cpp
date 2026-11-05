class Solution {
public:
    int m ,n;
    int dirs[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

    void dfs(int i, int j, vector<vector<char>>& board){
        if(i<0||j<0||i>=m||j>=n)return;
        if(board[i][j]!='O')return;

        board[i][j]='S'; //represent safe;
        for(auto& dir:dirs){
            dfs(i+dir[0],j+dir[1],board);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i = 0;i<m;i++){
            dfs(i,0,board);
            dfs(i,n-1,board);
        }
        for(int i = 0;i<n;i++){
            dfs(0,i,board);
            dfs(m-1,i,board);
        }
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='S')board[i][j]='O';
            }
        }
    }
};