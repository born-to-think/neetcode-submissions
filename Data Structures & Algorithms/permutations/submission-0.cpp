class Solution {
public:

    void compute(vector<int>&nums, vector<vector<int>>& ans, vector<int>&v )
    {
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int& num:nums)
        {
            if(num!=11){
                int temp = num;
                v.push_back(num) ;
                num=11;

                compute(nums,ans,v);

                num = temp;
                v.pop_back();

            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        compute(nums,ans,v);

        return ans;
    }
};