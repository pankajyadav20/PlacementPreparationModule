class TimeMap {
public:
 unordered_map<string, vector<pair<string, int>>> mp; // [key, vec[val, time]]
    TimeMap() {   
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key];
        int start = 0, end = (int)v.size()-1;
        while(start <= end)
        {
            int mid = start+(end-start)/2;
            v[mid].second > timestamp ? end = mid-1 : start = mid+1; 
        }
                return end < 0 ? "" : v[end].first;
    }

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */