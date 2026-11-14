class Solution {
public:
	int wordlen;
	int bfs(const string& beginWord, const string& endWord,unordered_map<string,unordered_set<string>>& mp,unordered_map<string,bool>&vis){
		int dist = 1;
		queue<string> q;
		q.push(beginWord);

		int cs;
		while(cs=q.size()){
			for(int i=0;i<cs;i++){
				string curr = q.front();q.pop();
				if(vis[curr])continue;
				vis[curr]=true;
				if(curr==endWord)return dist;
				
				for(int j = 0;j<wordlen;j++){
					string temp = curr;
					temp[j]='*';
					for(auto s: mp[temp]){
						if(s!=curr){
							q.push(s);		
						}
					}
				}
			}
			dist++;

		}

		return 0;
	}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordlen = beginWord.size();
        int n = wordList.size();

        unordered_map<string,unordered_set<std::string>> mp;
        unordered_map<string,bool> vis;
        for(int i = 0;i<=n;i++){
            string s;
            if(i==n){
                s = beginWord;
            }else{
                s = wordList[i];
            }
            vis[s]=false;
            for(int j = 0;j<wordlen;j++){
                string temp =  s;
                temp[j]='*';
                mp[temp].insert(s);
            }
        }

        return bfs(beginWord,endWord,mp,vis);

    }
};
