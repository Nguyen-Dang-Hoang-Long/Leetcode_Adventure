using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Result
        vector<int> res;
        // Give an empty hash
        unordered_map<int, size_t> found;
        // In a loop find = target - num in nums 
        for (int i = 0; i < nums.size(); i++) {
            res.clear();
            // if find in nums, return the pair
            auto it = found.find(target - nums[i]);
            if (it != found.end()) {
                res.push_back(i);
                res.push_back(it->second);
                sort(res.begin(), res.end());
                break;
            }
            // Else, store the new num in hash
            found[nums[i]] = i;
        }
        return res;
    }
};