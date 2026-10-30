class Solution {
private:
    int n;
    vector<vector<string>> res;
    vector<string>board;
    
    vector<bool> valid_col;
    vector<bool> valid_pdiag;
    vector<bool> valid_ndiag; 


    void compute(int i)
    {
        if(i==n){
            res.push_back(board);
            return;
        }
        for(int j = 0;j<n;j++){
            if( valid_col[j] && valid_pdiag[i+j] && valid_ndiag[j-i+n-1] ){
                board[i][j] = 'Q';
                valid_col[j]=false;
                valid_pdiag[i+j]=false;
                valid_ndiag[j-i+n-1] = false;

                compute(i+1);
                
                board[i][j]='.';
                valid_col[j]=true;
                valid_pdiag[i+j]=true;
                valid_ndiag[j-i+n-1] = true;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        res.clear(); 
        board = vector<string>(n, string(n,'.') );

        valid_col = vector<bool> (n,true);
        valid_pdiag = vector<bool>(2*n+1, true);
        valid_ndiag = vector<bool>(2*n-1, true);
        
        compute(0);
        
        return this->res;
    }
};