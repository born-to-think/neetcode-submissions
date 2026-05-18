class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(const auto& s: strs){
            string sortedS = s;
            sort(sortedS.begin(),sortedS.end());
            res[sortedS].push_back(s);
        }

        vector< vector<string> > final_res;
        for(auto& pair: res){
            final_res.push_back( pair.second );
        }
        return final_res;
    }
    
};
