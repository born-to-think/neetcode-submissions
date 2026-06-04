class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;

        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target){
                return m;
            }
            //one liner shortcut-----------*(nums[m]>target?&r:&l) = nums[m]>target?m-1:m+1;
            else if(nums[m]> target){
                //shrink to left
                r=m-1;
            }
            else{
                //shrink to right
                l=m+1;
            }
        }

        return -1;
    }
};