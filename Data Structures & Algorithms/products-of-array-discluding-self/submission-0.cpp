using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix, suffix, res;
        prefix = suffix = {1};
        for (int i = 0; i < nums.size(); i++) {
            prefix.push_back(prefix.back() * nums[i]);
            suffix.push_back(suffix.back() * nums[nums.size() - i - 1]);
        }
        for (int i = 0; i < nums.size(); i++ ) {
            res.push_back(prefix[i] * suffix[nums.size() - i - 1]);
        }
        return res;
    }
};