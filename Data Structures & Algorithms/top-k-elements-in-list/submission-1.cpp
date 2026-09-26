using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create ds
        unordered_map<int, int> numFreq;
        vector<vector<int>> freqNums(nums.size() + 1);
        // Put in num->freq lookup
        for (int num : nums) {
            numFreq[num]++;
        }
        // Convert to freq->num lookup
        for (auto& [num, freq] : numFreq) {
            freqNums[freq].push_back(num);
        }
        // Return top k freqNums
        vector<int> res;
        int reserve = k;
        for (int i = 0; i < freqNums.size() && k > 0; i++) {
            if (freqNums[freqNums.size() - 1- i].empty()) continue;
            for (int num : freqNums[freqNums.size() - 1 - i]) {
                res.push_back(num);
                k--;
            }
        }
        return res;
    }
};