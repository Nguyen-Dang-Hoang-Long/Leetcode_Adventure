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
    void remove_if () {
        if (cur < cap) cur++;
        else {
            key_value.erase(cache.front().first);
            cache.pop_front();
        }
    }
    void update(int key) {
        cache.splice(cache.end(), cache, key_value[key]);
    }
public:
    LRUCache(int capacity) : cap (capacity) {key_value.reserve(capacity);}
    
    // Access a key, if not exist -1, if yes, update least use, return key
    int get(int key) {
        if (!exists(key)) return -1;
        update(key);
        return key_value[key]->second;        
    }
    
    // Add a key, if exist, update least use, if not, add, if max, remove, then update
    void put(int key, int value) {
        if (!exists(key)) {
            remove_if();
            cache.push_back({key, value});
            key_value[key] = --cache.end();
        }
        else key_value[key]->second = value;
        update(key);
    }
};