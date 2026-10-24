using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        // Empty or one
        if (s.size() <= 1) return s.size();

        // Window
        auto l = s.begin();
        auto r = l;

        // Current max length of any character, 
        // and best result 
        int max, best;
        max = best = r-l+1; 

        // Keep track of letter (current window)
        vector<int> count(26,0);
        count[*l - 'A']++;

        // If its not the end
        while (r+1 != s.end()){
            // Expand window
            r++;
            // Record the new char
            count[*r - 'A']++;
            // Record the longest char
            if (count[*r - 'A'] > max) max = count[*r - 'A'];
            // Current k needed
            int k_needed = (r-l+1) - max;
            // Not enough k
            if (k_needed > k) {
                // Remove one char from count (leftmost)
                count[*l - 'A']--;
                // Move window up
                l++;
                // Recalc longest char
                for (int i = 0; i < count.size(); i++) 
                    if (count[i] > max) max = count[i];
            }
            // Enough k
            else {
                if (r-l+1 > best) best = r-l+1;
            }
        }

        // Return best
        return best;
    }
};
