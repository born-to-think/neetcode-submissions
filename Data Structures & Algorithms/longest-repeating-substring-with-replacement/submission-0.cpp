class Solution {
public:

    int find_max(unordered_map<char,int>& mp){
        int max_=0;
        for(auto&p:mp){
            max_=max(max_,p.second);
        }
        return max_;
    }

    int characterReplacement(string s, int k) {

        int res=0;
        unordered_map<char,int> mp;
        int l=0;
        for(int r=0;r<s.size();r++){
            char c = s[r];
            mp[c]++;
            int curr_len = r-l+1;

            int max_freq = find_max(mp);

            //while not valid increase l;
            while(curr_len-max_freq >k){
                mp[s[l]]--;
                l++;
                curr_len--;
                max_freq = find_max(mp);
            }

            res = max(res,curr_len);
        }

        return res;

    }
};