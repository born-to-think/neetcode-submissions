class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int m = l + (h-l)/2;

            if(target == nums[m])return m;
            if(target == nums[l])return l;
            if(target == nums[h])return h;

            if(target > nums[m]){
                if(nums[l]<nums[h])l=m+1;
                else{
                    if (nums[m]>nums[h])l=m+1;
                    else{
                        if(target<nums[h])l=m+1;
                        else h=m-1;
                    }
                }
            }
            else{
                if(nums[l]<nums[h])h=m-1;
                else{
                    if(nums[m]<nums[h])h=m-1;
                    else{
                        if(target>nums[l])h=m-1;
                        else l=m+1;
                    }
                }
            }
        }
        
        return -1;  
    }
};
