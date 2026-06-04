class Solution {
public:
    int carFleet(float target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)v[i]={position[i],speed[i]};
        sort(v.rbegin(),v.rend());

        int fleet_count = 0;
        float last_time = 0;
        

        for(auto&p: v){
            float t = (target-p.first)/p.second;
            if(t>last_time){
                last_time=t;
                fleet_count++;
            }
        }
        return fleet_count;
    }
};