class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> nums = nums2;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i = 0; i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j = i+1;
            int k = n-1; ////////

            // find all pairs from [j,k] such that nums[i] + pair = 0;
            int curr_sum;

            while(j<k){
                if(j > i+1 && nums[j-1]==nums[j]){j++;continue;}
                if(k < n-1 && nums[k+1]==nums[k]){k--;continue;}
                curr_sum = nums[i] + nums[j] + nums[k];
                if(curr_sum>0)k--;
                else if(curr_sum<0)j++;
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }

        }

        return ans;
    }
};
