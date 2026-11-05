class TimeMap {
public:
    map<pair<string,int>,string> mp;
    map<string,int> tp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int> p = {key,timestamp};
        mp[p] = value;
        if(tp.find(key)==tp.end() || tp[key]<=timestamp )
            tp[key]=timestamp;
    }
    
    string get(string key, int timestamp) {
        if(tp.find(key)!=tp.end()){
            return mp[{key,tp[key]}];
        }

        return "";
    }
};
