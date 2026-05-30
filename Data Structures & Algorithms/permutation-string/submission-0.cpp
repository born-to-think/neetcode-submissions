class Solution {
public:
    bool checkInclusion(string str1, string str2) {
        int n1 = str1.size(),  n2 = str2.size(); 
        if(n1>n2)return false;
        
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<n1;i++){
            mp1[str1[i]]++;
            if(i==n1-1)break;
            mp2[str2[i]]++;
        }

        int l=0;
        int r=n1-1;
        while(r<n2){
            char c1 = str2[l];
            char c2 = str2[r];

            mp2[c2]++;
            if(mp1==mp2)return true;
            
            if(mp2[c1]>1)mp2[c1]--;
            else mp2.erase(c1);

            l++;r++;
        }
        return false;
    }
};
