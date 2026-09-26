using namespace std;
class Solution {
private:
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // bsearch rows (in the matrix)
        int l = 0;
        int r = matrix.size()-1;
        // setup
        int idx = -1;
        // while theres still at least 1 row
        while(l<=r) {
            // mid row idx
            int mid = l + (r-l)/2;
            // if target >= begin of row and <= end of row
            if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1]) idx = mid;
            // target is less than begin of row, search lower half
            else if (target < matrix[mid][0]) r = mid-1;
            // target is more than end of row, search higher half
            else l = mid+1;
            // found, out
            if (idx != -1) break;
        }
        // not found
        if (idx == -1) return false;
        // reuse, bsearch cells (in the row)
        l = 0;
        r = matrix[idx].size()-1;
        // while theres still at least 1 row
        while (l<=r) {
            // mid cell
            int mid = l + (r-l)/2;
            // if found, return, else, bsearch adjustments
            if (target == matrix[idx][mid]) return true;
            else if (target < matrix[idx][mid]) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};