class Solution {
public:
    int INF = INT_MAX;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n);
        vector<int> minDist(n,INF);

        int Cost=0;

        int curr = 0;
        minDist[curr]=0;
        vis[curr]=true;
        for(int j=0;j<(n-1);j++){
            int next=curr;
            int best_dist = INF;
            for(int i = 0;i<n;i++){
                if(!vis[i]){
                    int new_dist = abs(points[curr][0]-points[i][0]) + abs(points[curr][1]-points[i][1]);
                    if(new_dist<minDist[i]) minDist[i]=new_dist;
                    if(minDist[i]<best_dist){best_dist = minDist[i];next = i;}
                }
            }
            
            vis[next]=true;
            curr=next;
            Cost+=best_dist;
            
        }

        return Cost;

    }
};
