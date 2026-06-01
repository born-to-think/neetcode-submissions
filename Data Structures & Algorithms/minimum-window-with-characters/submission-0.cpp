class Solution {
public:
    
    bool check(unordered_map<char,int> t_mp, unordered_map<char,int> str_mp){
        for(auto p:t_mp){
            if(! str_mp.count(p.first))return false;
            if(str_mp[p.first] < p.second)return false;
        }
        return true;
    }

    // int count=0;
    // void print_map(unordered_map<char,int> mp, string s=""){
    //     return;
    //     cout<< "Map "<<count++<< "(" << s <<"):- "   <<endl;
    //     for(auto& p:mp){
    //         cout<<p.first<<": "<<p.second<<" ;"<<endl;
    //     }
    //     cout<<endl<<endl;
    // }

    string minWindow(string& str, string& t) {
        unordered_map<char,int> t_mp;
        for(char c:t)t_mp[c]++;
        // print_map(t_mp," T map to match ");

        string ans="";
        int min_len = INT_MAX;

        unordered_map<char,int> str_mp;
        int l=0;
        for(int r = 0; r<str.size(); r++){
            char c2 = str[r];
            str_mp[c2]++;
            // print_map(str_mp,"Outside Wile loop");


            while(check(t_mp,str_mp)){
                char c1 = str[l]; 
                int curr_len = r-l+1;
                if(curr_len<min_len){
                    ans=str.substr(l,curr_len);
                    min_len=curr_len;
                }
                l++;
                if(str_mp[c1]>1)str_mp[c1]--;
                else str_mp.erase(c1);
                // print_map(str_mp,"---Inside While Loop");
            }



        }

        return ans;

    }
};