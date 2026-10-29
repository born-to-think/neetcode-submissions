class Solution {
public:

    void compute(vector<int>&nums, vector<vector<int>>&ans, vector<int>&v, int i){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        int curr = nums[i];
        v.push_back( curr );
        compute(nums,ans,v,i+1);
        v.pop_back();

        while(i<nums.size() && nums[i]==curr)i++;
        compute(nums,ans,v,i);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        compute(nums,ans,v,0);
        return ans;
    }
};