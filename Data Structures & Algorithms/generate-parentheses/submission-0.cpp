class Solution {
public:

    void compute(vector<string>&res, string&curr, int open, int close)
    {
        if(!open && !close){
            res.push_back(curr);
            return;
        }
        if(open){
            curr.push_back('(');
            compute(res,curr,open-1,close);
            curr.pop_back();
        }
        if(close && close>open){
            curr.push_back(')');
            compute(res,curr,open,close-1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        compute(res,s,n,n);
        return res;
    }
};
