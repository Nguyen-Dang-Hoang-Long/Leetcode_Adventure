class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initiate double ptr at 0
        auto slow = nums.begin();
        auto fast = nums.begin();
        // Use the val as next index
        slow = nums.begin() + *slow;
        fast = nums.begin() + *(nums.begin() + *fast);
        // Floyd's cycle detection, if slow == fast => cycle
        while (slow != nums.end() && 
        fast != nums.end() && 
        *slow != *fast) {
            slow = nums.begin() + *slow;
            fast = nums.begin() + *(nums.begin() + *fast);
        }
        // Once cycle detected, create another slow
        // Move both slow, once their values collide
        // value is the answer
        auto dup = nums.begin();
        while (dup != nums.end() && 
        slow != nums.end() && 
        *dup != *slow) {
            slow = nums.begin() + *slow;
            dup = nums.begin() + *dup;
        }
        return *dup;
    }
};
