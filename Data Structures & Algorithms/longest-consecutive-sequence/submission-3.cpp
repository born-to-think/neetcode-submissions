class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> lookup(nums.begin(),nums.end());
        int max_len=0;

        for(int num :nums){
            if(!lookup.contains(num-1)){
                int n = num;
                int len = 1;
                while( lookup.contains(++n) )  len++;
                max_len = max(max_len,len);
            }
        }
        return max_len;
    }
};
