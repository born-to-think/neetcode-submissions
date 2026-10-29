class Solution {
public:
    

    bool is_palindrome(const string&s,int left, int right){
        while(left < right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void compute(const string& word, vector<vector<string>>& ans, vector<string_view>& curr_part,int start)
    {
        if(start == word.size()){
            ans.emplace_back(curr_part.begin(), curr_part.end());
            return;
        }

        for(int end = start; end<word.size(); end++){
            if(!is_palindrome(word,start,end) )continue;
            
            string_view curr = string_view(word.data()+start,  (end+1) -start );
            curr_part.push_back(curr);
            compute(word,ans,curr_part,end+1);
            curr_part.pop_back();

        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string_view> curr_part;
        int start = 0;
        compute(s,ans,curr_part,start);
        return ans;
    }
};