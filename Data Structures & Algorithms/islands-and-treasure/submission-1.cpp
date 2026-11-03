class Solution {
public:
    
    
    void islandsAndTreasure(vector<vector<int>>& grid) {    
        int m=grid.size();
        int n = grid[0].size();
        int UNVISITED = (1U<<31)-1;

        queue<pair<int,int>> q;

        for(int i = 0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            pair<int,int> curr = q.front();q.pop();
            int r = curr.first;
            int c = curr.second;
            for(int (&dir)[2]:dirs){
                int nr  = r + dir[0];
                int nc = c + dir[1];
                if(nc>=0 && nr>=0 && nr<m && nc<n){
                    if(grid[nr][nc] == UNVISITED){
                        grid[nr][nc] = grid[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};
