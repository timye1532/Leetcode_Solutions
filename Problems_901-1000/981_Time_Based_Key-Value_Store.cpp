class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyToTime;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyToTime[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!keyToTime.count(key)) return "";
        if (timestamp < keyToTime[key][0].first) return "";
        
        int l = 0;
        int r = keyToTime[key].size() - 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (keyToTime[key][mid].first < timestamp) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (keyToTime[key][r].first <= timestamp) {
            return keyToTime[key][r].second;
        }
        if (keyToTime[key][l].first <= timestamp) {
            return keyToTime[key][l].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */