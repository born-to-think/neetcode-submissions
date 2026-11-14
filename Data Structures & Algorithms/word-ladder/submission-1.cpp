class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        unordered_set<string> words(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);

        int cs;
        while((cs = q.size())){
            res++;
            for(int i = 0;i<cs;i++){
                string curr = q.front();q.pop();
                if(curr==endWord)return res;
                
                for(int j = 0;j<curr.length();j++){
                    char org = curr[j];
                    for(char c = 'a';c<='z';c++){
                        if(c==org)continue;
                        curr[j]=c;
                        if( words.find(curr)!=words.end() ){
                            q.push(curr);
                            words.erase(curr);
                        }
                    }
                    curr[j]=org;
                }
            }
        }


        return 0;
    }
};
