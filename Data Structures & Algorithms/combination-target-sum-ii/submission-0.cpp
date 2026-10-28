class Solution {
public:

    void dfs(vector<int>& cands, vector<vector<int>>&ans, vector<int>&curr_v, int i, int target)
    {
        if(target==0){
            ans.push_back(curr_v);
            return;
        }
        if(i==cands.size() || target<0)return;

        if(cands[i]>target)return;

        curr_v.push_back(cands[i]);
        dfs(cands,ans,curr_v,i+1,target-cands[i]);
        curr_v.pop_back();

        int j = i;
        while( j < cands.size() && cands[j]==cands[i])j++;
        dfs(cands,ans,curr_v,j,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& cands, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        sort(cands.begin(),cands.end());
        dfs(cands, ans, v,0,target);
        return ans;
    }
};