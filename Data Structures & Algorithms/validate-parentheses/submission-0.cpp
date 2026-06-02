class Solution {
public:
    
    bool isValid(string s) {

        unordered_map<char,char> corr;
        corr['(']=')';
        corr['{']='}';
        corr['[']=']';

        stack<char> stk;
        for(char c:s){
            if(corr.find(c)!=corr.end()){
                stk.push(c);
            }else{
                if(stk.empty() || c != corr[stk.top()])return false;
                else stk.pop();
            }
        }
        return stk.empty();
        
    }
};