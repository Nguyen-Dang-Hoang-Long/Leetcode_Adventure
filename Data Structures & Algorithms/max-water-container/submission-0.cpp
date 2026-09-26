using namespace std;
class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Res
        int max = numeric_limits<int>::min();

        // 2 ptr algo
        vector<int>::iterator left = heights.begin();
        vector<int>::iterator right = heights.end() - 1;

        // Iterate
        while (left < right) {
            // Calc area
            int area = (right - left) * min<int>(*left, *right);
            // New max if new > max
            if (area > max) max = area;
            // Move the column with the lowest height
            if (*left > *right) right--;
            else left++;
        }
        // return
        return max;
    }
};