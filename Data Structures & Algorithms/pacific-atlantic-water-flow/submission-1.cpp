class Solution {
public:
    int m,n;
    vector<vector<bool>> reachA;
    vector<vector<bool>> reachB;

    void dfs(int i, int j, int ph, const vector<vector<int>>& heights,vector<vector<bool>>&reach){
        if(i<0 || j<0 || i>=m || j>=n)return;
        if(reach[i][j])return;
        
        if(i>0 && j>0 && i<(m-1)&& j<(n-1)&& heights[i][j]<ph)return;

        reach[i][j]=true;
        int nh = heights[i][j];
        dfs(i-1,j  ,nh,heights,reach);
        dfs(i+1,j  ,nh,heights,reach);
        dfs(i  ,j-1,nh,heights,reach);
        dfs(i  ,j+1,nh,heights,reach);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        reachA = vector<vector<bool>> (m, vector<bool>(n, false));
        reachB = vector<vector<bool>> (m, vector<bool>(n, false));

        dfs(0,0,0,heights,reachA);
        dfs(m-1,n-1,0,heights,reachB);

        vector<vector<int>> res;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if( reachA[i][j] && reachB[i][j] )    res.push_back({i,j});
            }
        }
        return res;
    }
};
