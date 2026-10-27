//https://leetcode.com/problems/word-search-ii/


class Solution {
public:
    
    struct TrieNode{
        array<TrieNode* , 26> childs;
        bool isWord = false;
        int word_index = -1;
    };

    void addWord(TrieNode* root, string word, int w){
        TrieNode* curr = root;

        for(char c:word){
            if(! curr->childs[c-'a'] ) curr->childs[c-'a'] = new TrieNode();
            curr = curr->childs[c-'a'];
        }

        curr->isWord = true;
        curr->word_index = w;
    }
    
    void compute(vector<vector<char>>& board,int m, int n, vector<string>& ans, vector<string>& words,
                    int i, int j, TrieNode* parent )
    {
        if(j<0 || j>=n || i<0 || i>=m || board[i][j]=='#') return ;
        
        char curr_char = board[i][j];
        TrieNode* curr = parent->childs[  curr_char - 'a'  ];
        
        if(! curr ) return; //no child in trie // so need to select include it;

        board[i][j] = '#';

        if(curr->isWord ){
            ans.push_back( words[curr->word_index] );
            curr->isWord = false; //for restricting repetition
        }

        compute(board,m,n,ans,words ,i-1,j  ,curr);
        compute(board,m,n,ans,words ,i+1,j  ,curr);
        compute(board,m,n,ans,words ,i  ,j-1,curr);
        compute(board,m,n,ans,words ,i  ,j+1,curr);

        board[i][j] = curr_char;

        
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        ans.reserve(1000);
        
        int m = board.size();
        int n = board[0].size();

        TrieNode* root = new TrieNode();
        for(int w=0; w< words.size(); w++) addWord(root, words[w], w);

        
        for(int i = 0;  i<m ;i++){
            for(int j=0; j<n; j++){
                compute(board, m, n, ans,words , i, j, root);        
            }
        }
        

        return ans;
    }
};