class Solution {
public:
    bool isPalindrome(string s) {
        int s = s.size();
        for(int i=0;i<s%2;i++){
            if(s[i]!=s[s-1-i])return false;
        }
        return true;
    }
};
