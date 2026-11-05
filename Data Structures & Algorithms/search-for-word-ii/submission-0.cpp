//https://leetcode.com/problems/word-search-ii/


class Solution {
public:
    
    
    bool compute(vector<vector<char>>& board,vector<vector<bool>>& included ,int m, int n, 
                    int i, int j, const string& word, int idx ){
        if(idx == word.size())return true;

        //checking all 4 adjecents
        //up
        {
            if( (j-1) >= 0 ){
                if( board[i][j-1] == word[idx]  && !included[i][j-1] ){
                    
                    included[i][j-1] = true;
                    bool r = compute(board, included, m, n, i, j-1, word, idx + 1 );
                    included[i][j-1] = false;

                    if(r)return true;
                }
            }
        }
        //down
        {
            if( (j+1) < n){
                if( board[i][j+1] == word[idx]  && !included[i][j+1] ){
                    
                    included[i][j+1] = true;
                    bool r = compute(board, included, m, n, i, j+1, word, idx + 1 );
                    included[i][j+1] = false;

                    if(r)return true;
                }
            }
        }
        //left
        {
            if( (i-1) >= 0){
                if( board[i-1][j] == word[idx]  && !included[i-1][j] ){
                    
                    included[i-1][j] = true;
                    bool r = compute(board, included, m, n, i-1, j, word, idx + 1 );
                    included[i-1][j] = false;

                    if(r)return true;
                }
            }
        }
        //right
        {
            if( (i+1) < m ){
                if( board[i+1][j] == word[idx]  && !included[i+1][j] ){
                    
                    included[i+1][j] = true;
                    bool r = compute(board, included, m, n, i+1, j, word, idx + 1 );
                    included[i+1][j] = false;

                    if(r)return true;
                }
            }
        }

        return false;
        
    }

    bool wordFound(vector<vector<char>>& board, vector<vector<bool>>& included , int m, int n, string& word){
        
        char first = word[0];
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == first){
                    included[i][j] = true;
                    bool r = compute(board, included, m, n, i, j, word, 1);  //idx = 1 representing sequence from 2nd char of word not first
                    included[i][j] = false;

                    if(r)return true;
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        ans.reserve(1000);
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> included(m, vector<bool>(n,false) );

        for(string& word : words){
            if(wordFound(board, included, m, n, word))
                ans.push_back( word);
        }

        return ans;
    }
};