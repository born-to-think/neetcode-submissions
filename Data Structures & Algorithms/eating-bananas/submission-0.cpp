class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        int M = 0;
        for(int b:piles)M=max(M,b);
        
        int min_k=M;

        int l = 1;
        int h = M;
        while(l<h){

            int k = (l+h)/2;
            //calculating hours taken by this k
            int h_taken=0;
            for(int b:piles){
                h_taken += (b+k-1)/k;
            }

            if(h_taken > hours){
                l = k+1;
            }else{
                h=k;
                min_k=min(min_k,k);
            }


        } 

        return min_k;
    }
};