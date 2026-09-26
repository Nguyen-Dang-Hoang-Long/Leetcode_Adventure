using namespace std;
class Solution {
private:
    unordered_map<string, vector<string>> hashMap;
    string hashFunction (vector<int> alphabet) {
        string res;
        for (int num : alphabet) {
            res.push_back(num);
            res.push_back('#');
        }
        return res;
    }
    

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Res
        vector<vector<string>> res;
        // Hashcode format
        vector<int> alphabet(26);
        // Loop through each word
        for (string& str: strs) {
            // Refresh hashcode buffer
            fill(alphabet.begin(), alphabet.end(), 0);
            // Convert into hash code
            for (char c: str) {
                // If not lower, lower first
                if (c < 'a' || c > 'z') {
                    c = tolower(c);
                }
                // Convert
                alphabet[c - 'a']++;
            }
            // Hash and store in hashmap
            hashMap[hashFunction(alphabet)].push_back(str);
        }
        
        // Recollect and return
        for (auto& [hashCode, hashVector] : hashMap) {
            res.push_back({});
            for (string str : hashVector) {
                res[res.size()-1].push_back(str);
            }
        }
        return res;

    }
};