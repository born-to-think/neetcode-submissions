class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(string &s: strs){
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;

        int ov_index=0;
        while(ov_index<s.size()){
            int i = ov_index;
            int j = 0;
            while(s[i+j]!='#')j++;

            int curr_len = stoi( s.substr(i,j) );

            i+= j+1;
            string str = s.substr(i,curr_len);
            res.push_back(str);
            i+=curr_len;

            ov_index=i;


        }

        return res;
        
    }
};
