class Solution {
public:
    int dp(int n, vector<int>&nums,vector<int>&DP){
        if(DP[n]!=-1)return DP[n];
        return DP[n] = max(
            dp(n-1,nums,DP),
            dp(n-2,nums,DP)+nums[n]
            );
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return nums[0];

        vector<int>DP(n,-1);
        DP[0]=nums[0];
        DP[1]=max( nums[0],nums[1] );
        return dp(n-1,nums,DP);
    }
};
