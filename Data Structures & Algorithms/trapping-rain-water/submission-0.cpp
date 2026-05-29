class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if(n==1 || n==2)return 0;

        int res=0;

        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int left_max=0;
        int right_max=0;

        int j=n;
        for(int i = 0; i<n;i++){
            j--;
            left[i]=left_max;
            right[j]=right_max;

            left_max = max(left_max, heights[i]);
            right_max = max(right_max,heights[j]);
        }
        for(int i=0;i<n;i++){
            int water = min(left[i],right[i]);
            if(water>heights[i]){
                res+= water-heights[i];
            }
        }

        return res;
        

    }
};