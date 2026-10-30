class Solution {
public:
    void compute(const string& digits,const vector<string>&keymap, vector<string>&res, string&curr, int i)
    {
        if(i==digits.size()){
            res.push_back(curr);
            return;
        }

        for(char c: (keymap[digits[i] - '0']) )
        {
            curr.push_back(c);
            compute(digits,keymap,res,curr,i+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};

        vector<string>keymap{
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        

        vector<string> res;
        string curr;

        compute(digits,keymap,res,curr,0);

        return res;

    
    }
};
