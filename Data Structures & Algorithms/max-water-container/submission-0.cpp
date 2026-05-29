class Solution {
public:

    int area(vector<int>& heights, int x, int y){
        int width = abs(y-x);
        int height = min( heights[x], heights[y] );
        return width*height;
    }

    int maxArea(vector<int>& heights) {
        int res = 0;
        int j = 0, k= heights.size()-1;
        while(j<k){
            res = max ( res, area(heights,j,k) );
            if(heights[j]<heights[k])j++;
            else k--;
        }

        return res;
    }
};
