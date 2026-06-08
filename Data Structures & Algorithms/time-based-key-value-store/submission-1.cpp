class TimeMap {
public:
    map<pair<string,int>,string> mp;
    map<string,vector<int>> tp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int> p = {key,timestamp};
        mp[p] = value;
        tp[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(tp.find(key)!=tp.end()){
            vector<int>& v = tp[key];
            sort(v.begin(),v.end());
            for(int i = v.size()-1; i>=0; i--){
                if(timestamp>=v[i]){
                    return mp[{key,v[i]}];
                }
            }
        }

        return "";
    }
};
