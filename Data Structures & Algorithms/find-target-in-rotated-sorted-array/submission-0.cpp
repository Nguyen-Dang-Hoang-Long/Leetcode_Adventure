using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find inflection point
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int m = l + (r-l)/2;
            if (nums[m] < nums[r]) r = m;
            else l = m+1;
        }
        int inflect = l;
        // 1 partition 
        if (inflect == 0) {
            // binary search as normal
            int l1 = 0, r1 = nums.size()-1;
            while (l1 <= r1) {
                int m1 = l1 + (r1 - l1)/2;
                if (target == nums[m1]) return m1;
                else if (target > nums[m1]) l1 = m1+1;
                else r1 = m1-1;
            }
        }
        else {
            // dual binary search
            int l1 = 0, r1 = inflect-1;
            int l2 = inflect, r2 = nums.size()-1;
            while (l1 <= r1) {
                int m1 = l1 + (r1 - l1)/2;
                if (target == nums[m1]) return m1;
                else if (target > nums[m1]) l1 = m1+1;
                else r1 = m1-1;
            }
            while (l2 <= r2) {
                int m2 = l2 + (r2 - l2)/2;
                if (target == nums[m2]) return m2;
                else if (target > nums[m2]) l2 = m2+1;
                else r2 = m2-1;
            }
        }
        return -1;
    }
};
