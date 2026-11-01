class Solution {

private:
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<  pair<int,int> > pq;

        for(int i = 0; i<points.size(); i++ ){
            
            int xi = points[i][0];
            int yi = points[i][1];
            int dist = xi*xi + yi*yi;

            if(pq.size()<k){
                pq.push({dist, i});
                continue;
            }
            //k sized heap is present now
            if( dist < pq.top().first ){
                pq.pop();
                pq.push({dist,i});
            }

        }
        // k closest elemnts indixes now we know;
        vector<vector<int>> res;
        while(pq.size()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        
        }
        return res;
    }
};
