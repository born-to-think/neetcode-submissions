class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        deque<int> dq;

        int l=0;
        for(int r=0;r<nums.size();r++){
            int curr = nums[r];

            while(!dq.empty() && nums[dq.back()] < curr )dq.pop_back();
            dq.push_back(r);

            if(r+1>=k){
                ans.push_back(nums[dq.front()]);
                l++;
                if(dq.front()<l)dq.pop_front();
            }

        }
        return ans;
    }
};