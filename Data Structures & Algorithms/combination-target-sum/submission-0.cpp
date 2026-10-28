class Solution {
public:

    void compute(vector<int> &cands, vector<vector<int>>& res, int i, vector<int>& curr_v,  int rem_target){
        if(rem_target == 0){
            res.push_back(curr_v);
            return;
        }
        if(i == cands.size() || rem_target<0 )return;
        
        //early pruning because no of increasing order no further solution will be possible either
        if(cands[i] > rem_target)return;

       
        // ALL POSSIBLE SOLUTIONS WHICH CAN HAVE CANDS[i] in it for any frequency;
        curr_v.push_back(cands[i]);
        compute(cands, res, i, curr_v, rem_target - cands[i]);
        curr_v.pop_back();



        // ONCE REACHED HERE, ALLL FUTURE SOLUTIONS WILLL NEVER HAVE CANDS[i];    
        compute(cands,res,i+1,curr_v,rem_target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> v;

        sort(candidates.begin(),candidates.end());

        compute(candidates,res, 0,  v, target);

        return res;
    }
};