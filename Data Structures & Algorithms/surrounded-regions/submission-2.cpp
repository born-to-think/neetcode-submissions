class Solution {
public:
    int m,n;
    bool dfs(int i, int j,vector<vector<char>>& board, vector<pair<int,int>>& COs){
        


        if(i<0 || j<0|| i>=m || j>=n)return false;
        if(board[i][j]=='X' ||board[i][j]=='V')return true;

        //here only fresh O comes
        board[i][j]='V';
        COs.emplace_back(i,j);

        return (
            dfs(i  ,j-1,board,COs) &&
            dfs(i-1,j  ,board,COs) &&
            dfs(i  ,j+1,board,COs) &&
            dfs(i+1,j  ,board,COs)
        );
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n=board[0].size();
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='O'){
                    vector<pair<int,int>> COs;
                    bool captured = dfs(i,j,board,COs);
                    for(auto& [r,c]:COs){
                        board[r][c] = (captured?'X':'N');
                    }
                } 
            }
        }
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'N')board[i][j]='O';
            }
        }
    }
};
