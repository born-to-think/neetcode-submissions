class Solution {
public:

    string simplify(string s){
        string simple = "";
        for(char c:s){
            if(c>='a' && c<='z'){
                simple.push_back(c);
            }
            else if(c>='A' && c<='Z'){
                c-=('A'-'a');
                simple.push_back(c);
            }
            else if(c>='0'&&c<='9'){
                simple.push_back(c);
            }
        }
        return simple;
    }
    bool isPalindrome(string s) {
        s = simplify(s);
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else return false;
        }
        return true;
    }
};
