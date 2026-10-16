using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // String is empty or of size 1
        if (s.size() <= 1) return s.size();

        // String is of size 2+
        auto l = s.begin();
        auto r = l+1;

        // hash
        unordered_set<char> dup;
        dup.insert(*l);

        // max
        int max = 0; 

        // widen or shrink as needed
        while (r != s.end()) {

            // If dup
            while (dup.contains(*r)) {
                dup.erase(*l); 
                l++; 
            }
            // Not dup 
            // Update
            dup.insert(*r);
            if (r - l + 1 > max) max = r - l + 1;  
            r++;
        }
        return max;
    }
};
