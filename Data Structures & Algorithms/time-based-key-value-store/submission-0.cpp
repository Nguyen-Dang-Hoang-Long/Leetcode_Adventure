using namespace std;
class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> hashmap;
public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (hashmap.find(key) == hashmap.end()) return "";
        auto& array = hashmap[key];
        int l = 0, r = array.size()-1;
        string res = "";
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (array[mid].first <= timestamp) {
                res = array[mid].second;
                l = mid+1;
            }
            else r = mid-1;
        }
        return res;
    }
};