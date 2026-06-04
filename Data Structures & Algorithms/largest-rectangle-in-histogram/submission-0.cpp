class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int max=0;
        stack<pair<int,int>> s;

        int j=0;
        int idx=0;
        
        for(j=0;j<H.size();j++){
            idx=j;
            while(!s.empty() && s.top().first>H[j]){
                auto it = s.top();
                int area = (j-it.second)*it.first;
                max = area>max?area:max;

                idx=it.second;
                s.pop();

            }
            if(s.empty() || s.top().first!=H[j]){
                s.push( { H[j], idx } );
            }
            
        }

        while(!s.empty()){
           auto it = s.top();
                int area = (j-it.second)*it.first;
                max = area>max?area:max;
                s.pop();
        }
        return max;
    }
};