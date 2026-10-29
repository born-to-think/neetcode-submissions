class Solution {
public:

    void backtrack(vector<int>&cands, vector<vector<int>>&ans, vector<int>&v, int start, int target){
        
        if(target == 0){
            ans.push_back(v);
            return;
        }

        for(int i = start; i<cands.size(); i++){
            if(i>start && cands[i]==cands[i-1])continue;
            if(cands[i]>target)break;
            

            v.push_back(cands[i]);
            backtrack(cands,ans,v,i+1,target-cands[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& cands, int target) {
        sort(cands.begin(),cands.end());
        vector<vector<int>> ans;
        vector<int>v;
        backtrack(cands,ans,v,0,target);
        return ans;
    }
};
