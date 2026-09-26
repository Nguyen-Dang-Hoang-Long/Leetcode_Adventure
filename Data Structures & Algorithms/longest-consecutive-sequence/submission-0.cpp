using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Put all in a set
        unordered_set<int> hashset (nums.begin(), nums.end());
        // Loop
        std::pair<int,int> num_count (0,0);
        for (int num: nums) {
            if (hashset.contains(num-1)) continue; // not leader
            // is leader
            int cur_count = 0;
            int i = 0;
            while (hashset.contains(num+i)) {
                cur_count++;
                i++;
            }
            if (cur_count > num_count.second) {
                num_count = {num, cur_count};
            }
        }
        return num_count.second;
    }
};