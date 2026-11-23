class Solution {
public:

    bool dfs(char c,vector<vector<char>>& graph ,string& topo){
        graph[c]['S'] = 'A'; //marking active;

        for(char adj = 'a' ;adj <='z';adj++){
            if(graph[c][adj] =='e')
            {
                if(graph[adj]['S'] == 'A')//CYCLE;
                    return true;
                if(graph[adj]['S']=='U')
                {
                    bool c = dfs(adj,graph,topo);
                    if(c)return true;
                }
            }
        }
        topo.push_back(c);
        graph[c]['S']='\0'; //marking visited<->notfound
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        vector<vector<char>> graph(256,vector<char>(256,'\0'));
    
        for(char c:words[0])graph[c]['S']='U';
        
        for(int curr = 1;curr<words.size();curr++){
            bool k=true;
            for(int j=0;j<=words[curr].size();j++){        
                graph[words[curr][j]]['S']='U';

                if(k && words[curr-1][j]!=words[curr][j]){
                    k=false;
                    if(words[curr][j]=='\0') {
                        //it means order is wring because substring is in order "after" the longer string
                        return "";
                    }
                    if(words[curr-1][j]!='\0'){
                        graph[words[curr-1][j]][words[curr][j]]='e'; //e represent edge
                    }
                }
            }
        }

        //now we have graph ready! 
        string topo;
        for(char c='a';c<='z';c++){
            if( graph[c]['S']=='U' )
            {
                bool cycle = dfs(c,graph,topo);
                if(cycle) return "";
            }
        }
        reverse(topo.begin(),topo.end());
        return topo;
        
    }
};
