class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size(),0);

        //temp, index
        stack<pair<int,int>> st;

        for(int r=0;r<temps.size();r++){
            while(!st.empty() && st.top().first < temps[r]){
                ans[st.top().second] = r-st.top().second  ;
                st.pop();
            }
            st.push({temps[r],r});
        }
        return ans;
    }
};