class Solution {
public:
    int comp(int n, vector<int>&cost, vector<int>&DP){
        if(n<2)return 0;
        if(DP[n]!=-1)return DP[n];
        int from_min_1 = comp(n-1,cost,DP) + cost[n-1];
        int from_min_2 = comp(n-2,cost,DP) + cost[n-2];
        return DP[n] = min( from_min_1,from_min_2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>DP(101,-1);
        int dst = cost.size();
        return comp(dst,cost,DP);
    }
};
