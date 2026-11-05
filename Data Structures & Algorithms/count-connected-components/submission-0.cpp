class Solution {
public:
    void dfs(int node, vector<vector<int>>&graph, vector<bool>&vis){
        vis[node]=true;
        for(int adj:graph[node]){
            if(!vis[adj])dfs(adj,graph,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<bool>vis(n,false);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,graph,vis);
            }
        }
        return cnt; 
    }
};
