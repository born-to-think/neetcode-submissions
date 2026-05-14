class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> table;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(table.find(diff)!=table.end()){
                return {table[diff],i};
            }
            table.insert({nums[i],i});
        }
        return {};
    }
};
