using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // if s2 less then s1
        if (s2.size() < s1.size()) return false;
        // s1 window
        vector<int> sw1(26,0);
        for (char c : s1) sw1[c-'a']++;
        // s2 window
        vector<int> sw2(26,0);
        // window length
        int len = s1.size();
        // window
        auto l = s2.begin();
        auto r = l + len -1;
        // while window still that length
        while (r != s2.end()) {
            // scan window to see the letters
            auto scan = l;
            for (; scan!=r+1; scan++) {
                sw2[*scan -'a']++;
            }
            // match the 2 windows
            bool found = true;
            for (int i = 0; i < sw1.size(); i++)
                if (sw1[i] != sw2[i]) 
                    found = false;
            // if complete match
            if (found) return true;
            // not match, move up, reset window
            l++; r++;
            sw2.assign(26, 0);
        }
        return false;
    }
};
