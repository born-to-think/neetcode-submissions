class Solution {
public:

    int access(vector<int>& nums, int index){
        if(index<0) return INT_MIN;
        int s = nums.size();
        if(index>=s)return INT_MAX;
        return nums[index];
    }

    


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int CASE_DOUBLE_MEDIAN = ( (n1+n2)%2 == 0);


        //first median_index in even case, only median_index in odd case;
        int k_median1_index = (n1+n2-CASE_DOUBLE_MEDIAN) / 2 ;
        //k1 >= 0; sure


        int median1 = 0;
        int median2 = 0;

        int i_lower_bound = max(0 , k_median1_index - n2);
        int i_upper_bound = min(n1 , k_median1_index);
        
        while(i_lower_bound<=i_upper_bound){
            int i = (i_lower_bound + i_upper_bound) / 2;
            int j = k_median1_index - i;

            int sk = min(  access(nums1, i), access(nums2, j) );
            
            if( sk >= access(nums1, i-1)  &&  
                sk >= access(nums2, j-1) 
            ) //desired sk found
            
            {
                median1 = sk;

                if( access(nums1,i) <= access(nums2,j) )
                    median2 = min(  access(nums1, i + 1), access(nums2, j) );
                else 
                    median2 = min(  access(nums1, i), access(nums2, j + 1) );


                break;
            }

            else if(sk < access(nums1, i-1)){
                i_upper_bound = i - 1;
            }

            else {
                i_lower_bound = i +1;
            }

        }



        //-----------------------------------------------------------------------------------

        if( CASE_DOUBLE_MEDIAN ) //two median case;
        {
            return ((double)median1 + (double)median2)/2;
        }
        else
        {
            return (double)median1;
        }


    }
};