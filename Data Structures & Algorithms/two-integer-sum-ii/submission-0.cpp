class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int diff_target = target - nums[i];
            if( mp.count(diff_target) ){
                return { mp[diff_target], i+1};
            }
            mp[ nums[i] ]=i +1;
        }
        return {};
    }
};
