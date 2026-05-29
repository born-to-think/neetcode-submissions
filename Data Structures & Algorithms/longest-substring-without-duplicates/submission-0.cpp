class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_set<char> s;
        int i = 0, j=0;

        int curr_len=0;
        int max_len=0;
        while(j<str.size()){
            char c = str[j];
            while(s.contains(c)){
                s.erase(str[i]);
                i++;
                curr_len--;
            }
            curr_len++;
            s.insert(c);
            max_len = max(max_len,curr_len);
            j++;
        }


        return max_len;
    }
};