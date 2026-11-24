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
        int prev2 = 0;
        int prev1 = 0;
        for(int val:nums){
            int curr = max(prev2+val,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
