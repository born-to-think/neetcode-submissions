class Solution {
public:

    enum State : uint8_t{
        ABSENT = 0,
        UNVISITED = 1,
        ACTIVE = 2,
        DONE = 3
    };

    bool generate_adj(const vector<string>&words, bool adj[26][26]){
        for (size_t i = 1; i < words.size(); ++i) {
            const std::string& prev = words[i - 1];
            const std::string& curr = words[i];
            size_t minLen = std::min(prev.size(), curr.size());

            size_t j = 0;
            while (j < minLen && prev[j] == curr[j]) ++j;

            if (j < minLen) {
                adj[prev[j] - 'a'][curr[j] - 'a'] = true;
            } else if (prev.size() > curr.size()) {
                return false; // Invalid prefix order
            }
        }
        return true;
    }


    bool hasCycle
    (int u, const bool adj[26][26], uint8_t state[26],string& topo)
    {
        state[u] = ACTIVE;

        for(int v = 0 ;v<26;v++){
            if( !adj[u][v] ) continue;
            if( state[v]==ACTIVE )return true;
            if( state[v]==UNVISITED && hasCycle(v,adj,state,topo) )return true;
            // it will not bother about ABSENT or DONE nodes!
        }

        topo.push_back( static_cast<char>(u+'a') );
        state[u]=DONE; //marking visited<->notfound
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        uint8_t state[26] = {};
        for(const string& word:words){
            for(char ch:word){
                state[ch-'a'] = UNVISITED;
            }
        }
        
        bool adj[26][26] ={};
        if(!generate_adj(words, adj))return "";

        //now we have graph ready! 
        string topo; topo.reserve(26);
        for(int u = 0;u<26;u++){
            if( state[u] == UNVISITED && hasCycle(u,adj,state,topo) )
                return "";
        }
        reverse(topo.begin(),topo.end());
        return topo;
        
    }
};
