class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r = mat.size();
        int c = mat[0].size();

        int l = 0;
        int h = r*c-1;

        while(l<=h){
            int m = (l+h)/2;
            
            int el = mat[m/c][m%c];

            if(el == target)return true;

            if(el>target) h=m-1;
            else l=m+1; 
        }
        return false;
    }
};
