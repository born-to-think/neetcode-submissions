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
            //// what is the explaination of why we updated only smaller height index??
            // https://youtu.be/ZHQg07n_tbg?si=oL6OjYRVxq2vU41r
            // because suppose smaller height = x;
            // it is enivitable to get any better answer using x whatever the heights in "WHOLE Array" are....
            // if x is valueable, it already has contributed in the above instruction and result of x (ie. max possible result x can ever give) is stored in res,
            // so why preserve x?
            if(heights[j]<heights[k])j++;
            else k--;
        }

        return res;
    }
};
