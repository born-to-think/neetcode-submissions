class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int dirs[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
        int m = grid.size();
        int n = grid[0].size();
        int fresh_count = 0;

        //queue setup
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1)fresh_count++;
            }
        }

        if(!fresh_count)return 0;



        int timer = 0;
        while(!q.empty()){
            int cs = q.size();
            int flag = 0;
            for(int i = 0; i<cs; i++){
                auto [r,c] = q.front();q.pop();
                for(auto& dir: dirs){
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if(nr<0 || nc<0 || nr>=m || nc>=n)continue;
                    if(grid[nr][nc]  == 1){
                        flag = 1;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh_count--;
                    }
                }
            }
            timer+=flag;
        }
        if(fresh_count)return -1;
        return timer;

    }
};
