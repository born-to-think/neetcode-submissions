class Solution {
public:

    void compute(vector<int>& nums, int n, vector<vector<int>>& ans, int i,vector<int>prev){
        if(i==n){
            ans.push_back(prev);
            return;
        }
        
        compute(nums, n, ans, i+1, prev);

        prev.push_back(nums[i]);
        compute(nums, n, ans, i+1, prev);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        compute(nums, nums.size(), ans, 0,v);
        return ans;
    }
};
