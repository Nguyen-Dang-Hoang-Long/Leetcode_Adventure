using namespace std;
class LRUCache {
private: 
    // key and node of value
    unordered_map<int,list<pair<int,int>>::iterator> key_value;
    // key value pair
    list<pair<int,int>> cache;
    int cap;
    int cur = 0;
    // find exist by key
    bool exists (int key) const {
        return key_value.find(key) != key_value.end();
    }
    // remove the least used node
    void remove () {
        key_value.erase(cache.front().first);
        cache.pop_front();
    }
    void update(int key) {
        if (cur == 0 || cur == 1) return;
        cache.push_back({key, key_value[key]->second});
        cache.erase(key_value[key]);
        key_value[key] = (--cache.end());
    }
public:
    LRUCache(int capacity) : cap (capacity) {}
    
    // Access a key, if not exist -1, if yes, update least use, return key
    int get(int key) {
        if (!exists(key)) return -1;
        update(key);
        return key_value[key]->second;        
    }
    
    // Add a key, if exist, update least use, if not, add, if max, remove, then update
    void put(int key, int value) {
        if (!exists(key)) {
            cache.push_back({key, value});
            key_value[key] = (--cache.end());
            if (cur < cap) cur++;
            else remove();
        }
        else key_value[key]->second = value;
        update(key);
    }
};