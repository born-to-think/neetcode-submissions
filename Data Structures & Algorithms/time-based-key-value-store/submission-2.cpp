class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        auto& v = mp[key];
        pair<int, string> p = {timestamp, value};

        // given in constraints that all timestamps in increasing order;
        v.push_back(p);
    }

    string get(string key, int timestamp) {
        if (mp.find(key) != mp.end()) {

            auto& v = mp[key];

            int i = find_index(v, timestamp);

            if (i >= 0) {
                return v[i].second;
            }
        }

        return "";
    }

private:
    // BINARY SEARCH
    int find_index(vector<pair<int, string>>& v, int timestamp) {
        if (v.size() == 0)
            return -1;
        // we want a timestamp_prev index just <= timestamp
        int result = -1;
        int l = 0;
        int r = v.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= timestamp) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
