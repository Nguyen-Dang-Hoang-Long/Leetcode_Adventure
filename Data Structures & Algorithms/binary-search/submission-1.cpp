using namespace std;
class Solution {
private: 
    int binary_search (int l, int r, vector<int>& nums, int target) {
        // zero size array
        if (l > r) return -1;
        // if found return pos
        int idx = l + (r-l)/2;
        int mid = nums[idx];
        if (target == mid) return idx;
        else if (target < mid) return binary_search (l, idx - 1, nums, target);
        else return binary_search (idx + 1, r, nums, target);
    }
public:
    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, nums, target);
    }
};