class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n,1);
        vector<int> post(n,1);
        
        int prod=1;
        for(int i = 1;i<n;i++){
            prod*=nums[i-1];
            pre[i]=prod; 
        }
        prod=1;
        for(int j = n-2; j>=0 ; j--){
            prod*=nums[j+1];
            post[j]=prod;
        }

        vector<int> res(n);
        for(int i=0;i<n;i++)res[i] = pre[i]*post[i];

        return res;

        
        
    }
};
