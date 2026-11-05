class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::nth_element(nums.begin(),nums.begin()+k, nums.end(), greater<int>() );
        return nums[k-1];
    }
};
