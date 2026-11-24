class Solution {
public:
    
    int dp(int n, vector<int>&DP){
        if(DP[n]!=-1)return DP[n];
        return DP[n] = dp(n-1,DP)+dp(n-2,DP);
    }
    int climbStairs(int n) {
        vector<int>DP(46,-1);
        DP[1]=1;
        DP[2]=2;
        return dp(n,DP);    
    }
};
