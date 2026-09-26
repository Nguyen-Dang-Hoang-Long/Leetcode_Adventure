using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Give an empty hash
        unordered_map<int, size_t> found;
        // In a loop find = target - num in nums 
        for (int i = 0; i < nums.size(); i++) {
            // if find in nums, return the pair
            auto it = found.find(target - nums[i]);
            if (it != found.end()) {
                return {static_cast<int>(it->second), i};
            }
            // Else, store the new num in hash
            found[nums[i]] = i;
        }
        return {};
    }
};