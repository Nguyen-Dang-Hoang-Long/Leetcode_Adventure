using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        // parse string
        string p;
        for (char c : s) {
            // if not alphanumeric
            if (!(c >= '0' && c <= '9') && 
                !(c >= 'A' && c <= 'Z') &&
                !(c >= 'a' && c <= 'z')) continue;
            p.push_back(c);
        }
        int distance = 'a' - 'A';
        for (int i = 0; i < p.size(); i++) {
            if (p[i] >= 'A' && p[i] <='Z') 
                p[i] = p[i] + distance;
            if (p[p.size() - i - 1] >= 'A' && p[p.size() - i - 1] <='Z') 
                p[p.size() - i - 1] = p[p.size() - i - 1] + distance;
            if (p[i] != p[p.size() - i - 1]) return false; 
        }
        return true;
    }
};