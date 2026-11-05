class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string &s: strs){
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        string l;
        
        bool string_reading=false;
        for(char c:s){
            if(string_reading){

            }
            if(c=='#'){

            }
        }
    }
};
