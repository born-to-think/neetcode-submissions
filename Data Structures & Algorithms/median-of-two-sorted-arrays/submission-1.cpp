class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nS = nums1.size(), nB = nums2.size();
        vector<int>& B = nS>=nnB ?nums1:nums2;
        vector<int>& S = nS<nB   ?nums1:nums2;
        if(nS>=nB){int temp = nB;nB=na;nA=temp;}
        //now we have two array B,S and nS,nB where B represents larger array;
        
        int total = nS+nB;
        int half = total/2;

        double ans=0.0;

        int l= 0;
        int r= nS-1;
        
        while(1){
            int mid =l+(r-l)/2;

            int i = mid; //S
            int j = half-i-2 ; //B

            //index <0  --> no element of array
            //index >=n --> whole array
            int Sleft   =   i>=0?       S[i]:   INT_MIN;
            int Sright  =   (i+1)<nS?   S[i+1]: INT_MAX;
            int Bleft   =   j>=0?       B[j]:   INT_MIN;
            int Bright  =   (j+1)<nB?   B[j+1]: INT_MAX;
            
            //partition is correct;
            if(Bleft<=Sright && Sleft<= Bright)
            {
                //odd
                if(total%2){
                    ans = min(Sright,Bright);
                    break;
                }
                //even
                else{
                    ans = (float)( min(Sright,Bright)+max(Sleft,Bleft) )/2;
                    break;
                }
            }
            

            //partition not correct;
            else if(Sleft>Bright) r = mid-1;
            else l=mid+1;
        }
        return ans;

    }

};
