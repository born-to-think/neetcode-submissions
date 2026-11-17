class Solution {
public:
    

    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();
        int INF = INT_MAX;
        int dirs[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>> cost(n,vector<int>(n,INF));
        set<pair<int,pair<int,int>>> st;

        cost[0][0]=grid[0][0];
        st.insert({grid[0][0],{0,0}});
        
        while(!st.empty()){
            int curr_level = (*st.begin()).first;
            int r=(*st.begin()).second.first;
            int c=(*st.begin()).second.second;
            st.erase(st.begin());
            if(r==(n-1)&&c==(n-1))return curr_level;
            if(curr_level > cost[r][c])continue;
            
            for(auto& dir:dirs){
                int nr = r+dir[0];
                int nc = c+dir[1];
                if(nr<0 || nc<0 || nr>=n || nc>=n) continue;
                
                int new_level = max(curr_level,grid[nr][nc]);
                if(new_level<cost[nr][nc]){
                    cost[nr][nc]=new_level;
                    st.insert({new_level,{nr,nc}});
                }
            }
            
        }   
        return cost[n-1][n-1];
    }
};
