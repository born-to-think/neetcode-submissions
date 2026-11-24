class Solution {
public:
    int INF = INT_MAX;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>old(n,INF);
        old[src]=0;
        
        for(int i=1;i<=k+1;i++){
            vector<int>new_=old;
            for(const auto& e:flights){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                int k = (old[u]!=INF)?old[u]+w:INF;
                
                if( k < new_[v] ) new_[v]=k;
            }
            old=std::move(new_);
        }
        return old[dst]==INF?-1:old[dst];
    }
};
