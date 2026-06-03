class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for(string &s:tokens){
            if(s.size()==1){
                switch(s[0]){
                    int a,b;
                    case '+':
                        //
                        b=ans.top();ans.pop();
                        a=ans.top();ans.pop();
                        ans.push( a+b );
                        break;
                    case '-':
                        //
                        b=ans.top();ans.pop();
                        a=ans.top();ans.pop();
                        ans.push( a-b );
                        break;
                    case '*':
                        //
                        b=ans.top();ans.pop();
                        a=ans.top();ans.pop();
                        ans.push( a*b );
                        break;
                    case '/':
                        //
                        b=ans.top();ans.pop();
                        a=ans.top();ans.pop();
                        ans.push( a/b );
                        break;
                    
                    default:
                        ans.push(stoi(s));

                }

            }
            else ans.push(stoi(s));
        }
        return ans.top();
    }
};