class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(!n)return {};

        vector<string>keymap{
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        
        string s(n,' ');

        vector<string> res{s};


        for(int j = n-1; j>=0; j--){
            
            string& options = keymap[digits[j]-'0'];
            int temp = res.size();
            bool first = true;

            for(char c:options){
                for(int t = 0; t<temp;t++){
                    if(first){
                        res[t][j]=c;
                    }
                    else{
                        string s = res[t];
                        s[j]=c;
                        res.push_back(s);
                    }
                }
                first=false;
            }

        }
        return res;

    
    }
};
