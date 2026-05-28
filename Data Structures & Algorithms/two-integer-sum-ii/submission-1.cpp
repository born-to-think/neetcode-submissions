class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        int cur_sum;
        while(i<j){
            cur_sum = nums[i]+nums[j];
            if(cur_sum>target)j--;
            else if(cur_sum<target)i++;
            else return{i+1,j+1};
        }
        return{};
    }
};
