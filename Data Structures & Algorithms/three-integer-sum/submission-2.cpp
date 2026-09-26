#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <cctype>
#include <numeric>
#include <unordered_set>
#include <functional>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Result
        vector<vector<int>> res;

        // Sort input array
        sort (nums.begin(), nums.end());

        // We need to find triplets of A + B + C = 0 => A + B = -C
        // Loop through C
        for (int i = 0; i < nums.size() - 2; i++) {
            int C = nums[i];
            if (i > 0 && C == nums[i-1]) continue;
            int target = (-1) * C;
            // Use 2 pointers approach to slowly approach the correct sum
            auto PtrA = nums.begin() + i + 1;
            auto PtrB = nums.end() - 1;
            // When both is not overlap (so unique nums)
            while (PtrA < PtrB) {
                int A = *PtrA;
                int B = *PtrB;
                // If found, push triplet
                if (A + B == target) {
                    res.push_back({A, B, C});
                    // Skip all duplicates of A & B
                    while (PtrA+1 != nums.end() && *(PtrA+1) == A) PtrA++;
                    while (PtrB != nums.begin() && *(PtrB-1) == B) PtrB--;
                    // Then move to the new unique numbers of A and B
                    PtrA++;
                    PtrB--;
                }
                // Else if less than, increase
                // Since its sorted, we simply move our left ptr right
                else if (A + B < target) PtrA++;
                // Else if more, decrease, move right ptr left
                else PtrB--;
            }
        }
        return res;
    }
};