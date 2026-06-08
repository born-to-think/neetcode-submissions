class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int h = n-1;
        int ans = INT_MAX;

        while(l<=h){
            //if all sorted
            if(nums[l]<=nums[h]){
                ans = min(ans,nums[l]);
                break;
            }

            int m = (l+h)/2;
            ans = min (ans,nums[m]);
            if(nums[m]>=nums[l]){
                //search right
                l=m+1;
            }
            else{
                //search left
                h=m-1;
            }

        }
        return ans;
    }
};