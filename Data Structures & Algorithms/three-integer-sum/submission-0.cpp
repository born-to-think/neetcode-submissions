class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i<n-2 ; i++){
            int target = -(nums[i]);
            int j=i+1;
            int k=n-1;
            int curr_sum;
            while(j<k){
                curr_sum = nums[j]+nums[k];
                if(curr_sum>target)k--;
                else if(curr_sum<target)j++;
                else {
                    ans.push_back( {i,j,k} );
                    // if(j+2<n && nums[j+1]==nums[j])j++;
                    // else if(k-2>0 && nums[k-1]==nums[k])k--;
                }
            }
        } 
        return ans;
    }
};
